# DExTer : Debugging Experience Tester
# ~~~~~~   ~         ~~         ~   ~~
#
# Copyright (c) 2018 by SN Systems Ltd., Sony Interactive Entertainment Inc.
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
"""Command for specifying an expected set of values for a particular watch."""

import difflib
import sys
import abc

from dex.command.CommandBase import CommandBase
from dex.heuristic import StepValueInfo


class _BaseMatcher(object):
    @abc.abstractmethod
    def check_match(self, expected_node, watch_value):
        pass


class _ValueMatcher(_BaseMatcher):
    def check_match(self, expected_node, watch_value):
        return expected_node == watch_value


class _SpecialAny(_BaseMatcher):
    def check_match(self, expected_node, watch_value):
        """Special any can only match once, if the expected node's been seen
           then it has matched once already.
        """
        return not expected_node.seen


class _SpecialAnyMultiple(_BaseMatcher):
    def check_match(self, expected_node, watch_value):
        """any multiple should continue to match until the next expected value
           is matched.
        """
        return not expected_node.RHS.match_watch_value(watch_value)


class _ExpectedValue(object):
    def __init__(self, expected_value, matcher):
        # Node base values.
        self.LHS = None
        self.RHS = None
        self.value = expected_value
        self.matcher = matcher
        self.misordered = False
        self.seen = False

    def get_RHS(self):
        return self.RHS

    def get_LHS(self):
        return self.LHS

    def match_watch_value(self, watch):
        return self.matcher(watch, self)


def _create_expected_node_list(expected_values):
    PreviousNode = None
    CurrentNode = None
    for value in expected_values:
        if isinstance(value, str):
            matcher = _ValueMatcher()
        else:
            matcher = value
        


def _check_watch_order(actual_watches, expected_values):
    start = _create_expected_node_list(expected_values)


def _check_watch_order(actual_watches, expected_values):
    """Use difflib to figure out whether the values are in the expected order
    or not.
    """
    differences = []
    actual_values = [w.value_info.value for w in actual_watches]
    value_differences = list(difflib.Differ().compare(actual_values,
                                                      expected_values))

    missing_value = False
    index = 0
    for vd in value_differences:
        kind = vd[0]
        if kind == '+':
            # A value that is encountered in the expected list but not in the
            # actual list.  We'll keep a note that something is wrong and flag
            # the next value that matches as misordered.
            missing_value = True
        elif kind == ' ':
            # This value is as expected.  It might still be wrong if we've
            # previously encountered a value that is in the expected list but
            #  not the actual list.
            if missing_value:
                missing_value = False
                differences.append(actual_watches[index])
            index += 1
        elif kind == '-':
            # A value that is encountered in the actual list but not the
            #  expected list.
            differences.append(actual_watches[index])
            index += 1
        else:
            assert False, 'unexpected diff:{}'.format(vd)

    return differences


class DexExpectWatchValue(CommandBase):
    def __init__(self, *args, **kwargs):
        if len(args) < 2:
            raise TypeError('expected at least two args')

        self.expression = args[0]

        special_values = DexExpectWatchValue.special_values().values()
        special_value_found = False
        for arg in args:
            if arg in special_values:
                special_value_found = True
                break

        self.values = [str(arg) for arg in args[1:]]
        try:
            on_line = kwargs.pop('on_line')
            self._from_line = on_line
            self._to_line = on_line
        except KeyError:
            self._from_line = kwargs.pop('from_line', 1)
            self._to_line = kwargs.pop('to_line', sys.maxsize)
        self._require_in_order = kwargs.pop('require_in_order', True)
        if not self._require_in_order and special_value_found:
            raise TypeError('cannot use require_in_order'
                            ' and special values together')
        if kwargs:
            raise TypeError('unexpected named args: {}'.format(
                ', '.join(kwargs)))

        # Number of times that this watch has been encountered.
        self.times_encountered = 0

        # We'll pop from this set as we encounter values so anything left at
        # the end can be considered as not having been seen.
        self._missing_values = set(self.values)

        self.misordered_watches = []

        # List of StepValueInfos for any watch that is encountered as invalid.
        self.invalid_watches = []

        # List of StepValueInfo any any watch where we couldn't retrieve its
        # data.
        self.irretrievable_watches = []

        # List of StepValueInfos for any watch that is encountered as having
        # been optimized out.
        self.optimized_out_watches = []

        # List of StepValueInfos for any watch that is encountered that has an
        # expected value.
        self.expected_watches = []

        # List of StepValueInfos for any watch that is encountered that has an
        # unexpected value.
        self.unexpected_watches = []

        super(DexExpectWatchValue, self).__init__()

    @property
    def line_range(self):
        return list(range(self._from_line, self._to_line + 1))

    @property
    def missing_values(self):
        return sorted(list(self._missing_values))

    @property
    def encountered_values(self):
        return sorted(list(set(self.values) - self._missing_values))

    def _handle_watch(self, step, watch):
        self.times_encountered += 1

        if not watch.could_evaluate:
            self.invalid_watches.append(StepValueInfo(step.step_index, watch))
            return

        if watch.is_optimized_away:
            self.optimized_out_watches.append(
                StepValueInfo(step.step_index, watch))
            return

        if watch.is_irretrievable:
            self.irretrievable_watches.append(
                StepValueInfo(step.step_index, watch))
            return

        if watch.value not in self.values:
            self.unexpected_watches.append(
                StepValueInfo(step.step_index, watch))
            return

        self.expected_watches.append(StepValueInfo(step.step_index, watch))
        try:
            self._missing_values.remove(watch.value)
        except KeyError:
            pass

    def __call__(self, step_collection):
        for step in step_collection.steps:
            loc = step.current_location

            if (loc.path == self.path and loc.lineno in self.line_range):
                try:
                    watch = step.watches[self.expression]
                except KeyError:
                    pass
                else:
                    self._handle_watch(step, watch)

        if self._require_in_order:
            # A list of all watches where the value has changed.
            value_change_watches = []
            prev_value = None
            for watch in self.expected_watches:
                if watch.value_info.value != prev_value:
                    value_change_watches.append(watch)
                    prev_value = watch.value_info.value

            self.misordered_watches = _check_watch_order(
                value_change_watches, [
                    v for v in self.values if v in
                    [w.value_info.value for w in self.expected_watches]
                ])

    @classmethod
    def special_values(cls):
        return {
            'any': _SpecialAny#####,
            #'any_multiple': _SpecialAnyMultiple,
            #'missing': _SpecialMissing,
            #'missing_multiple': _SpecialMissingMultiple,
            #'ignore': _SpecialIgnore,
            #'ignore_multiple': _SpecialIgnore
        }

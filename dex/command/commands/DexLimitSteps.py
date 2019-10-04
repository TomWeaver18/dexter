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
"""A Command that enables test writers to specify a limited number of break
points using a range and conditional predicate based on the value of a
variable.
"""

from dex.command.CommandBase import CommandBase

class DexLimitSteps(CommandBase):
    def __init__(self, *args, **kwargs):
        self.expression = args[0]
        self.values = [str(arg) for arg in args[1:]]
        self.from_line = kwargs.pop('from_line', 1)
        self.to_line = kwargs.pop('to_line', 999999)
        if kwargs:
            raise TypeError('unexpected named args: {}'.format(
                ', '.join(kwargs)))
        super(DexLimitSteps, self).__init__()

    def resolve_label(self, label_line_pair):
        # from_line and to_line could have the same label.
        label, lineno = label_line_pair
        if self.to_line == label:
            self.to_line = lineno
        if self.from_line == label:
            self.from_line = lineno

    def has_labels(self):
        return len(self.get_label_args()) > 0

    def get_label_args(self):
        return [label for label in (self.from_line, self.to_line)
                      if isinstance(label, str)]

    def eval(self):
        return self.expression

    @staticmethod
    def get_name():
        return __class__.__name__

    @staticmethod
    def get_subcommands() -> dict:
        return None

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
"""Base class for all DExTer commands, where a command is a specific Python
function that can be embedded into a comment in the source code under test
which will then be executed by DExTer during debugging.
"""

import abc
from typing import List

class CommandBase(object, metaclass=abc.ABCMeta):
    def __init__(self):
        self.path = None
        self.lineno = None
        self.raw_text = ''

    def get_label_args(self):
        return list()

    def has_labels(self):
        return False

    @abc.abstractstaticmethod
    def get_name():
        """This abstract method is usually implemented in subclasses as:
        return __class__.__name__
        """

    def get_watches(self) -> List[str]:
        return []

    @abc.abstractmethod
    def eval(self):
        """Evaluate the command.

        This will be called when constructing a Heuristic object to determine
        the debug score.

        Returns:
            The logic for handling the result of CommandBase.eval() must be
            defined in Heuristic.__init__() so a consitent return type between
            commands is not enforced.
        """

    @staticmethod
    def get_subcommands() -> dict:
        """Returns a dictionary of subcommands in the form {name: command} or
        None if no subcommands are required.
        """
        return None

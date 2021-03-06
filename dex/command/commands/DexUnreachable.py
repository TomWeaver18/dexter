# DExTer : Debugging Experience Tester
# ~~~~~~   ~         ~~         ~   ~~
#
# Copyright (c) 2019 by SN Systems Ltd., Sony Interactive Entertainment Inc.
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


from dex.command.CommandBase import CommandBase
from dex.dextIR import ValueIR


class DexUnreachable(CommandBase):
    """Expect the source line this is found on will never be stepped on to.

    DexUnreachable()

    See Commands.md for more info.
    """

    def __init(self):
        super(DexUnreachable, self).__init__()
        pass

    @staticmethod
    def get_name():
        return __class__.__name__

    def eval(self, debugger):
        # If we're ever called, at all, then we're evaluating a line that has
        # been marked as unreachable. Which means a failure.
        vir = ValueIR(expression="Unreachable",
                      value="True", type_name=None,
                      error_string=None,
                      could_evaluate=True,
                      is_optimized_away=True,
                      is_irretrievable=False)
        return {'DexUnreachable' : vir}

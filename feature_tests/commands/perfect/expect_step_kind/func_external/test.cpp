// Purpose:
//      Check that \DexExpectStepKind correctly counts 'FUNC_EXTERNAL' steps
//      for a trivial test. Expect one 'FUNC_EXTERNAL' per external call.
//
// REQUIRES: linux, clang, lldb
//
// RUN: dexter.py test --fail-lt 1.0 -w  \
// RUN:     --builder clang --debugger lldb --cflags "-O0 -g" -- %S \
// RUN:     | FileCheck %s
// CHECK: func_external:

#include <cstdlib>

int func(int i){
    return abs(i);
}

int main()
{
    func(0);
    func(1);
    return 0;
}

// DexExpectStepKind('FUNC_EXTERNAL', 2)

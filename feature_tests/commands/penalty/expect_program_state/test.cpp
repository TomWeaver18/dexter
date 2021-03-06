// Purpose:
//      Check that \DexExpectProgramState correctly applies a penalty when
//      an expected program state is never found.
//
// REQUIRES: linux, clang, lldb
//
// RUN: not dexter.py test --fail-lt 1.0 -w \
// RUN:     --builder clang --debugger lldb --cflags "-O0 -glldb" -- %S \
// RUN:     | FileCheck %s
// CHECK: expect_program_state:

int GCD(int lhs, int rhs)
{
    if (rhs == 0)   // DexLabel('check')
        return lhs;
    return GCD(rhs, lhs % rhs);
}

int main()
{
    return GCD(111, 259);
}

/*
DexExpectProgramState({
    'frames': [
        {
            'location': {
                'lineno': 'check'
            },
            'watches': {
                'lhs': '0', 'rhs': '0'
            }
        },
    ]
})
*/

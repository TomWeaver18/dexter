#include "simple.h"

int start = 0;

int foo_cannon(int count) {
  int result = 0;             // DexWatch('start', 'count', 'result')
  int ix = start;             // DexWatch('start', 'count', 'result', 'ix')
  if (ix != count) {          // DexWatch('start', 'count', 'result', 'ix')
    do {                      // DexWatch('start', 'count', 'result', 'ix')
      result += simple(ix);   // DexWatch('start', 'count', 'result', 'ix')
    } while (++ix != count);  // DexWatch('start', 'count', 'result', 'ix')
  }                           // DexWatch('start', 'count', 'result', 'ix')
  return result;              // DexWatch('start', 'count', 'result', 'ix')
}

int main(int argc, const char ** argv) {
  int loopBy = argc + 3;
  return foo_cannon(loopBy);
}

// DexExpectWatchValue('start',  '0',                     from_line=6, to_line=13)
// DexExpectWatchValue('count',  '4',                     from_line=6, to_line=13)
// DexExpectWatchValue('result', '0', '1', '3', '6',      from_line=6, to_line=13)
// DexExpectWatchValue('ix',     '0', '1', '2', '3', '4', from_line=7, to_line=13)
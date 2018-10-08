#include "simple.h"

int start = 0;

int foo_for(int count) {
  int result = 0;                                         // DexWatch('start', 'count', 'result')
  for (unsigned long long ix = start; ix != count; ++ix)  // DexWatch('start', 'count', 'result', 'ix')
    result += simple(ix);                                 // DexWatch('start', 'count', 'result', 'ix')
  return result;                                          // DexWatch('start', 'count', 'result')
}

int main(int argc, const char ** argv) {
  int loopBy = argc + 3;
  return foo_for(loopBy);
}

// DexExpectWatchValue('start',  '0',                from_line=6, to_line=9)
// DexExpectWatchValue('count',  '4',                from_line=6, to_line=9)
// DexExpectWatchValue('result', '0', '1', '3', '6', from_line=6, to_line=9)
// DexExpectWatchValue('ix',     '0', '1', '2', '3', from_line=7, to_line=8)
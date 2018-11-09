#include "simple.h"
int main(int argc, const char * argv[]) {
int result = 0;                           // DexWatch('result')
  for (int ix(0); ix != (argc+4); ++ix)   // DexWatch('result', 'ix')
    result += simple(ix);                 // DexWatch('result', 'ix')
  return result;                          // DexWatch('result')
}

// DexExpectWatchValue('result', '0', '1', '3', '6', '10', from_line=3, to_line=6)
// DexExpectWatchValue('ix', any, '0', '4', '3', '2', '1', from_line=4, to_line=5)

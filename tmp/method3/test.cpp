// Given a Dexter command DexLimitStepRange(<from>, <to>), only set break
// points and collection data from ranged denoted by the command.
// If no command is provided assume the whole program is to be stepped over.

#include <cstdio>

const unsigned int gArrSize = 256;
volatile int gArr[gArrSize];

int main(const int argc, const char * argv[]) {
  for (unsigned int ix = 0; ix != gArrSize; ++ix) {
    gArr[ix] = ix;            // DexLabel('main_start1')
    gArr[ix + 0] = ix + 1;    // DexLabel('main_start2')
    gArr[ix + 0] = ix + 5;    // DexLabel('main_start3')
    gArr[ix] = gArr[ix] + ix; // DexLabel('main_end')
  }
  return gArr[5] + gArr[9] + argc; // DexLabel('ret_end')
}


// only set breaks from 'from_line' to 'to_line' when ix is 0 or 5.

// DexLimitSteps('ix', 3, 8, from_line='main_start1', to_line='main_end')

// DexLimitSteps('ix', 3, 8, from_line='main_start2', to_line='main_end')

// DexLimitSteps('ix', 3, 8, from_line='main_start3', to_line='main_end')


// DexExpectWatchValue('ix', 3, 8, from_line='main_start1', to_line='main_end')

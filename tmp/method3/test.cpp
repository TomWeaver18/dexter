// Given a Dexter command DexLimitStepRange(<from>, <to>), only set break
// points and collection data from ranged denoted by the command.
// If no command is provided assume the whole program is to be stepped over.

const unsigned int gArrSize = 256;
volatile int gArr[gArrSize];

int main(const int argc, const char * argv[]) {
  for (unsigned int ix = 0; ix != gArrSize; ++ix) {
    gArr[ix] = ix;            // DexLabel('main_start')
    gArr[ix] = ix + 2;
    gArr[ix] = gArr[ix] + ix; // DexLabel('main_end')
  }
  return gArr[5] + gArr[9] + argc; // DexLabel('ret_end')
}


// only set breaks from 'from_line' to 'to_line' when ix is 0 or 5.

// DexLimitSteps('ix', 3, 8, from_line='main_start', to_line='main_end')

// DexExpectWatchValue('ix', 3, 8, from_line='main_start', to_line='main_end')

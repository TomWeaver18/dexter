// Given a Dexter command DexLimitStepRange(<from>, <to>), only set break
// points and collection data from ranged denoted by the command.
// If no command is provided assume the whole program is to be stepped over.

const unsigned int gArrSize = 256;
int gArr[gArrsize];

void initGlobal() {
  // collecting results from this loop should make this test rather slow.
  for (unsigned int ix = 0; ix != gArrSize; ++ix)
    gArr[ix] = ix;
}

void reInitGlobal() {
  for (unsigned int ix = 0; ix != gArrSize; ++ix) // DexLabel('reInit_start')
    gArr[ix] = ix;                                // DexLabel('reInit_end')
}

int getAResult(const int arg) {
  int res = 0       // DexLabel('res_start')
  res += arg + arg; // DexLabel('res_mid')
  return res;       // DexLabel('res_end')
}

int main(const int argc, const char * argv[]) {
  int result = 0;                   // DexLabel('main_start')
  int a = 1;
  int b = 2;
  result += a + b;
  result += result + a + b;
  result += result + a + b + argc;
  result += getAResult(argc);
  return result;                    // DexLabel('main_end')
}

// ! ! !
// only set breaks from 'from_line' to 'to_line' when ix is 0 or 5.
// DexLimitStepRange('ix', 0, 5, from_line='reInit_start', to_line='reInit_end')
// ! ! !

// ! ! !
// DexLimitStepRange(from_line='res_start', to_line='res_end')
// ! ! !

// DexExpectWatchType('res', 'int', from_line='res_mid', to_line='res_end')
// DexExpectWatchValue('res', 0, 2, from_line='res_mid', to_line='res_end')

// ! ! !
// DexLimitStepRange(from_line='main_start', to_line='main_end')
// ! ! !

// DeExpectWatchType('result', int, from_line='main_start', to_line='end')
// DexExpectWatchValue('result', 0, 3, 6, 10, from_line='main_start', to_line'end')

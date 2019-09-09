struct foo {
  static const size_t size = 7;
  int   a;
  int   b;
  short c;
  short data[size];
};

volatile foo * gpAwk;

inline void initABC(foo & bar, const int arg) {
  bar.a = 6 + arg;
  bar.b = 10 + arg;  // DexLabel('initABC_str')
  bar.c = 256 + arg; // DexLabel('initABC_end')
}

inline void initData(foo & bar, const int arg) {
  for (size_t ix = 0; ix != bar.size; ++ix) { // DexLabel('initData_str')
    bar.data[ix] = ix + arg;                  // DexLabel('initData_end')
  }
}

int doSomeMath(foo bar, const int arg) {
  int someMath = bar.a + bar.b +                        // DexLabel('math_str')
                 bar.data[arg + 1] + bar.data[arg + 4];
  return someMath;                                      // DexLabel('math_end')
}

inline int makeSomePointers(foo & bar) {
  if (bar.a) {                  // DexLabel('makeSomePointers_str')
    gpAwk = &bar;
    return 0;
  }
  return bar.a + bar.b + bar.c; // DexLabel('makeSomePointers_end')
}

int main(int argc, const char * argv[]) {
  argc -= 1;          // DexLabel('main_str')
  foo bar;
  //initABC(bar, argc);
  //initData(bar, argc);
  //makeSomePointers(bar);
  int mainThing = doSomeMath(bar, argc);

  return mainThing +
         bar.a +
         bar.b +
         bar.c +
         bar.data[1] +
         bar.data[6]; // DexLabel('main_end')
}

// DexExpectWatchType('bar', 'foo', from_line='main_str', to_line='main_end')

// DexExpectWatchValue('bar.a', 6, from_line='initABC_str', to_line='initABC_end')
// DexExpectWatchValue('bar.b', 0, 10, from_line='initABC_str', to_line='initABC_end')
// DexExpectWatchValue('bar.c', 0, from_line='initABC_str', to_line='initABC_end')

// DexExpectWatchValue('bar.a', 6, from_line='initData_str', to_line='initData_str')
// DexExpectWatchValue('bar.b', 10, from_line='initData_str', to_line='initData_str')
// DexExpectWatchValue('bar.c', 256, from_line='initData_str', to_line='initData_str')
// DexExpectWatchValue('bar.data[1]', 0, 1, from_line='initData_str', to_line='initData_str')
// DexExpectWatchValue('bar.data[6]', 0, 6, from_line='initData_str', to_line='initData_str')

// DexExpectWatchValue('bar.a', 6, from_line='math_str', to_line='math_end')
// DexExpectWatchValue('bar.b', 10, from_line='math_str', to_line='math_end')
// DexExpectWatchValue('bar.c', 256, from_line='math_str', to_line='math_end')
// DexExpectWatchValue('bar.data[1]', 1, from_line='math_str', to_line='math_end')
// DexExpectWatchValue('bar.data[6]', 6, from_line='math_str', to_line='math_end')

// DexExpectWatchValue('bar.a', 6, from_line='makeSomePointers_str', to_line='makeSomePointers_end')
// DexExpectWatchValue('bar.b', 10, from_line='makeSomePointers_str', to_line='makeSomePointers_end')
// DexExpectWatchValue('bar.c', 256, from_line='makeSomePointers_str', to_line='makeSomePointers_end')
// DexExpectWatchValue('bar.data[1]', 1, from_line='makeSomePointers_str', to_line='makeSomePointers_end')
// DexExpectWatchValue('bar.data[6]', 6, from_line='makeSomePointers_str', to_line='makeSomePointers_end')

// DexExpectWatchValue('bar.a', 0, 6, from_line='main_str', to_line='main_end')
// DexExpectWatchValue('bar.b', 0, 10, from_line='main_str', to_line='main_end')
// DexExpectWatchValue('bar.c', 0, 256, from_line='main_str', to_line='main_end')
// DexExpectWatchValue('bar.data[1]', 0, 1, from_line='main_str', to_line='main_end')
// DexExpectWatchValue('bar.data[6]', 0, 6, from_line='main_str', to_line='main_end')

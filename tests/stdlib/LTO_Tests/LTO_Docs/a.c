// --- a.c ---
#include "a.h"

static signed int i = 0; // DexLabel('cu_global_i_start')

void foo2(void) {
  i = -1;             // DexUncreachable()
}

static int foo3() {
  foo4();             // DexUncreachable()
  return 10;          // DexUncreachable()
}

int foo1(void) {
  int data = 0;
                      // DexLabel('foo1_data_start')
  if (i < 0)
    data = foo3();

  data = data + 42;
  return data;        // DexLabel('cu_global_i_end')
}

// DexExpectWatchValue('i', 0, from_line='cu_global_i_start', to_line='cu_global_i_end')
// DexExpectWatchType('i', 'int', from_line='cu_global_i_start', to_line='cu_global_i_end')

// DexExpectWatchValue('data', 0, 42, from_line='foo1_data_start', to_line='cu_global_i_end')
// DexExpectWatchType('data','int', from_line='foo1_data_start', to_line='cu_global_i_end')

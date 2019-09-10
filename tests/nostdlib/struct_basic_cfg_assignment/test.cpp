struct foo {
  int a;
  short b;
};

int main(const int argc, const char * argv[]) {
  foo a;
  a.a = argc;   // DexLabel('str')
  a.b = argc+1;
  foo b;
  b = a;
  return b.a;   // DexLabel('end')
}

// DexExpectWatchType('a', 'foo', from_line='str', to_line='end')
// DexExpectWatchType('b', 'foo', from_line='str', to_line='end')
// DexExpectWatchValue('b.a', 0, 1, from_line='str', to_line='end')
// DexExpectWatchValue('b.b', 0, 2, from_line='str', to_line='end')
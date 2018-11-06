int main(int argc, const char * argv[]) {
int result = 0;                           // DexWatch('result')
  for (size_t ix(0); ix != (argc+4); ++ix)    // DexWatch('result', 'ix')
    result += ix;                         // DexWatch('result', 'ix')
  return result;                          // DexWatch('result')
}

// DexExpectWatchValue('result', '0', '1', '3', '6', from_line=2, to_line=5)
// DexExpectWatchValue('ix', '0', '1', '2', '3', from_line=2, to_line=5)

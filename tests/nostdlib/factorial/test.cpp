unsigned long Factorial(int n) {
  volatile unsigned long fac = 1; // DexWatch('n')

  for (int i = 1; i <= n; ++i)
    fac *= i; // DexWatch('i', 'n', 'fac')

  return fac; // DexWatch('n', 'fac')
}

int main()
{
  return Factorial(8);
}

// REMOVE THIS !!!
// REMOVE THIS !!!
// DexExpectWatchValue('i', '1', '2', '3', '4', '5', any, '7', '8', on_line=12)
// REMOVE THIS !!!
// REMOVE THIS !!!


// DexExpectWatchValue('n', '8', on_line=9)

// DexExpectWatchValue('i', '1', '2', '3', '4', '5', any, '7', '8', on_line=12)
// DexExpectWatchValue('fac', '1', '2', '6', '24', '120', any_multiple, on_line=12)
// DexExpectWatchValue('n', '8', on_line=12)

// DexExpectWatchValue('fac', '40320', on_line=14)
// DexExpectWatchValue('n', '8', on_line=14)

// DexExpectStepKind('FUNC_EXTERNAL', 0)

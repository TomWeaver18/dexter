struct fooStruct {
  fooStruct(char n_char, short n_short, int n_int, long long int n_llint)
    : m_char(n_char), m_short(n_short), m_int(n_int), m_llint(n_llint) {}

  char          m_char;
  short         m_short;
  int           m_int;
  long long int m_llint;
};

fooStruct gFoo('a', 256, 128000, 67000000);

int main(const int argc, const char * argv[]) { // DexLabel('main_start')
  return gFoo.m_char; // DexLabel('main_end')
}

// DexExpectWatchType('gFoo',         'fooStruct',     from_line='main_start', to_line='main_end')
// DexExpectWatchType('gFoo.m_char',  'char',          from_line='main_start', to_line='main_end')
// DexExpectWatchType('gFoo.m_short', 'short',         from_line='main_start', to_line='main_end')
// DexExpectWatchType('gFoo.m_int',   'int',           from_line='main_start', to_line='main_end')
// DexExpectWatchType('gFoo.m_llint', 'long long int', from_line='main_start', to_line='main_end')

// DexExpectWatchValue('gFoo.m_char',  '\'a\'',  from_line='main_start', to_line='main_end')
// DexExpectWatchValue('gFoo.m_short', 256,      from_line='main_start', to_line='main_end')
// DexExpectWatchValue('gFoo.m_int',   128000,   from_line='main_start', to_line='main_end')
// DexExpectWatchValue('gFoo.m_llint', 67000000, from_line='main_start', to_line='main_end')

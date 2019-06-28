namespace shoeShop {
  namespace shopWarehouse {
    typedef int shoeBox;
  }
  typedef shopWarehouse::shoeBox shoe;
}

template <class T>
T two_of(T a) {
  T result = a + a; // DexWatch('a')
  return a;         // DexWatch('a')
}

int main(const int argc, const char * argv[]) {
  shoeShop::shoe single_nike = argc;
  auto pair_nikes = two_of<shoeShop::shoe>(single_nike);

  short single_crocc = argc;
  auto pair_croccs = two_of<short>(single_crocc);

  auto result = static_cast<int>(pair_croccs) + pair_nikes;

  return result;
}
// DexExpectWatchValue('a', '1', from_line=10, to_line=11)

// DexExpectWatchType('a', 'int', 'short', from_line=10, to_line=11)
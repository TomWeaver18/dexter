#ifndef FOO_STRUCT_H
#define FOO_STRUCT_H

struct fooStruct {
  fooStruct(
    char          n_char,
    short         n_short,
    int           n_int,
    long long int n_llint
  ) :
    m_char(n_char),
    m_short(n_short),
    m_int(n_int),
    m_llint(n_llint) {}

  char          m_char;
  short         m_short;
  int           m_int;
  long long int m_llint;
};

#endif

// --- main.c ---
#include <stdio.h>
#include "a.h"

void foo4(void) {
  printf("Hi\n"); // DexUncreachable()
}

int main() {
  return foo1();
}

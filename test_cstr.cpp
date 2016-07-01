#include "cstr.h"
#include <stdio.h>

template <typename String>
void test(String str) {
//  struct {}_=String();
  printf("%d: %s\n",str.size(),str.data());
}

int main()
{
  test(CSTR("Hello"));

  return 0;
}


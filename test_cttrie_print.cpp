#include "cttrie-print.h"
#include <stdio.h>

int main()
{
  auto trie=CtTrie::makeTrie(
    CSTR("Rosten"),
    CSTR("Raben"),
    CSTR("Rasen"),
    CSTR("Rasten"),
    CSTR("Raster"),
    CSTR("Rastender"),
    CSTR("Raban")
  );
  // trie is not constexpr, but decltype(trie) is.

  CtTrie::printTrie(trie);

  return 0;
}

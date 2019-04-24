#include "cttrie.h"
#include <stdio.h>
#include "lc_stringview.h"

int main(int argc,char **argv)
{
  const char *str=(argc>1) ? argv[1] : "abc";

  printf("%d\n",
    TRIE2(lc_stringview,str) return -1;
    CASE("abc") return 0;
    CASE("bcd") return 1;
    ENDTRIE
  );

  TRIE(str)
    printf("E\n");
  CASE("Rosten")
    printf("6\n");
  CASE("Raben")
    printf("0\n");
  CASE("Rasen")
    printf("1\n");
  CASE("Rasten")
    printf("2\n");
  CASE("Raster")
    printf("3\n");
  CASE("Rastender")
    printf("4\n");
  CASE("Raban")
    printf("5\n");
  ENDTRIE;

  return 0;
}

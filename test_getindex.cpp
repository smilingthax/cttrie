#include "getindex.h"
#include <stdio.h>

template <unsigned int... Is>
struct index_list {};

static inline void invoke()
{
}

template <typename Fn0,typename... Fns>
static inline void invoke(Fn0&& fn0,Fns&&... fns)
{
  fn0();
  invoke((Fns&&)fns...);
}

template <unsigned int... Is,typename... Fns>
void test1(index_list<Is...>,Fns&&... fns)
{
  invoke(pack_tools::get_index<Is>((Fns&&)fns...)...);
}

template <unsigned int... Is,typename... Ts>
void test2(Ts&&... args)
{
  { const int k[]={printf("%s ",pack_tools::get_index<Is>(args...))...}; (void)k; } // (,0) not needed
}

int main(int argc,char **argv)
{
  test1(index_list<1,0,1>(),[&](){
    printf("1 %d\n",argc);
  },[&](){
    printf("2\n");
  },[&](){
    printf("3\n");
  });

//  printf("%s\n",pack_tools::get_index<0>("The","other","thing"));
  test2<0,1,1,2>("The","other","thing");
  printf("\n");

  return 0;
}


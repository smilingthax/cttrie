#ifndef _CTTRIE_PRINT_H
#define _CTTRIE_PRINT_H

#include "cttrie.h"
#include <stdio.h>

namespace CtTrie {

// <typename String>  would be ambiguous...
template <unsigned char... Chars,unsigned int I>
void printTrie_hlp(string_t<Chars...> s,Transition<-1,int_c<I>>)
{
  printf("%d: %.*s\n",I,s.size(),s.data());
}

template <typename String=string_t<>>
void printTrie(TrieNode<>)
{
}

template <unsigned char... Chars,int Ch0,typename Next>
void printTrie_hlp(string_t<Chars...>,Transition<Ch0,Next>)
{
  printTrie<string_t<Chars...,Ch0>>(Next());
}

template <typename String=string_t<>,typename Transition0,typename... Transitions>
void printTrie(TrieNode<Transition0,Transitions...>)
{
  printTrie_hlp(String(),Transition0());
  printTrie<String>(TrieNode<Transitions...>());
}

} // namespace CtTrie

#endif

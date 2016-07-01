#ifndef _CTTRIE_H
#define _CTTRIE_H

/* Usage:

  TRIE(str)
    ... error case
  CASE("abc")
    ... str matches abc ...
  CASE("ad")
    ... etc
  ENDTRIE;   // <- trailing semicolon!

  - compile with optimization enabled!
  - cases may return a value
    -> return types must match! (deduced from error case)

*/

#include "cstr.h"
#include "getindex.h"
#include "stringview.h"

namespace CtTrie {

using pack_tools::detail::int_c;

template <int Char,typename Next>
struct Transition {};

template <typename... Transitions>
struct TrieNode : Transitions... {};

namespace detail {
  template <typename...> struct type_array {};

  struct nil {};

  template <bool B> using Sfinae=char(*)[2*B-1]; // just [B] does not work with MSVC and clang; MSVC still does weird things with [2*B-1]...
  // template <bool B> using Sfinae=typename std::enable_if<B>::type;

  template <unsigned int... Is>
  struct index_sequence {};

  template <unsigned int N,unsigned int... Is,typename =Sfinae<N==0>>
  constexpr index_sequence<Is...> make_index_sequence(...)
  { return {}; }

  template <unsigned int N,unsigned int... Is,typename =Sfinae<(N>0)>>
  constexpr auto make_index_sequence(...)
    -> decltype(make_index_sequence<N-1,N-1,Is...>(nil())) // argument forces ADL
  { return {}; }

  // end of new chain
  template <unsigned int Index>
  constexpr Transition<-1,int_c<Index>> transitionAdd(nil,string_t<0>) // strip trailing '\0'
  { return {}; }
//  constexpr Transition<-1,int_c<Index>> transitionAdd(nil,string_t<>) { return {}; }

  // create new chain
  template <unsigned int Index,unsigned char Ch0,unsigned char... Chars>
  constexpr Transition<Ch0,TrieNode<decltype(transitionAdd<Index>(nil(),string_t<Chars...>()))>> transitionAdd(nil,string_t<Ch0,Chars...>)
  { return {}; }

  template <unsigned int Index,unsigned char... Chars,typename... Prefix,typename... Transitions,
            typename =Sfinae<(sizeof...(Chars)==0 || sizeof...(Transitions)==0)>>
  constexpr auto insertSorted(nil,string_t<Chars...> s,TrieNode<Prefix...>,Transitions...)
    -> TrieNode<Prefix...,decltype(transitionAdd<Index>(nil(),s)),Transitions...>
  { return {}; }

  template <unsigned int Index,unsigned char Ch0,unsigned char... Chars,typename... Prefix,int Ch,typename Next,typename... Transitions,
            typename =Sfinae<(Ch>Ch0)>>
  constexpr auto insertSorted(nil,string_t<Ch0,Chars...> s,TrieNode<Prefix...>,Transition<Ch,Next>,Transitions...)
    -> TrieNode<Prefix...,decltype(transitionAdd<Index>(nil(),s)),Transition<Ch,Next>,Transitions...>
  { return {}; }

  template <unsigned int Index,typename String,typename... Transitions>
  constexpr auto trieAdd(TrieNode<Transitions...>)
    -> decltype(insertSorted<Index>(nil(),String(),TrieNode<>(),Transitions()...)) // nil forces adl
  { return {}; }

  template <unsigned int Index,unsigned char Ch0,unsigned char... Chars,typename... Prefix,int Ch,typename Next,typename... Transitions,
            typename =Sfinae<(Ch==Ch0)>>
  constexpr auto insertSorted(nil,string_t<Ch0,Chars...> s,TrieNode<Prefix...>,Transition<Ch,Next>,Transitions...)
    -> TrieNode<Prefix...,Transition<Ch,decltype(trieAdd<Index,string_t<Chars...>>(Next()))>,Transitions...>
  { return {}; }

  template <unsigned int Index,unsigned char Ch0,unsigned char... Chars,typename... Prefix,int Ch,typename Next,typename... Transitions,
            typename =Sfinae<(Ch<Ch0)>>
  constexpr auto insertSorted(nil,string_t<Ch0,Chars...> s,TrieNode<Prefix...>,Transition<Ch,Next>,Transitions...)
    -> decltype(insertSorted<Index>(nil(),s,TrieNode<Prefix...,Transition<Ch,Next>>(),Transitions()...))
  { return {}; }

  template <unsigned int I>
  constexpr TrieNode<> makeTrie(nil) // nil forces adl
  { return {}; }

  template <unsigned int I,typename String0,typename... Strings>
  constexpr auto makeTrie(nil,String0,Strings...)
    -> decltype(trieAdd<I,String0>(makeTrie<I+1>(nil(),Strings()...)))
  { return {}; }

  #include "cttrie_sw32.tcc"
  #include "cttrie_sw256.tcc"

  // handle trivial cases already here
  template <typename FnE,typename... Fns>
  constexpr auto checkTrie(TrieNode<> trie,stringview str,FnE&& fne,Fns&&... fns) // possible via Transition<-1>
    -> decltype(fne())
  {
    return fne();
  }
  template <int Char,typename Next,typename FnE,typename... Fns,typename =Sfinae<(Char>=0)>>
  constexpr auto checkTrie(TrieNode<Transition<Char,Next>> trie,stringview str,FnE&& fne,Fns&&... fns)
    -> decltype(fne())
  {
    return (!str.empty()) ? checkTrie(Next(),str.substr(1),(FnE&&)fne,(Fns&&)fns...) : fne();
  }

  template <typename... Transitions,typename FnE,typename... Fns>
  constexpr auto checkTrie(TrieNode<Transitions...> trie,stringview str,FnE&& fne,Fns&&... fns)
    -> decltype(fne())
  {
    return (!str.empty()) ? Switch(*str,str.substr(1),trie,(FnE&&)fne,(Fns&&)fns...) : fne();
  }

  template <unsigned int Index,typename... Transitions,typename FnE,typename... Fns>
  constexpr auto checkTrie(TrieNode<Transition<-1,int_c<Index>>,Transitions...>,stringview str,FnE&& fne,Fns&&... fns)
    -> decltype(fne())
  {
    return (str.empty()) ? pack_tools::get_index<Index>((Fns&&)fns...)()
                         : checkTrie(TrieNode<Transitions...>(),str,(FnE&&)fne,(Fns&&)fns...);
  }

  template <unsigned int... Is,typename ArgE,typename... Args>
  constexpr auto doTrie(index_sequence<Is...>,stringview str,ArgE&& argE,Args&&... args)
    -> decltype(argE())
  {
    return checkTrie(makeTrie<0>(nil(),pack_tools::get_index<(2*Is)>((Args&&)args...)...),
                     str,(ArgE&&)argE,
                     pack_tools::get_index<(2*Is+1)>((Args&&)args...)...);
  }

} // namespace detail

template <typename TrieNode,typename FnE,typename... Fns>
constexpr auto checkTrie(TrieNode trie,stringview str,FnE&& fne,Fns&&... fns)
  -> decltype(fne())
{
  return detail::checkTrie(trie,str,(FnE&&)fne,(Fns&&)fns...); // also used for adl dance
}

template <typename ArgE,typename... Args>
constexpr auto doTrie(stringview str,ArgE&& argE,Args&&... args)
  -> decltype(argE())
{
  return detail::doTrie(detail::make_index_sequence<sizeof...(args)/2>(),str,(ArgE&&)argE,(Args&&)args...);
}

// Strings must be string_t
template <typename... Strings>
constexpr auto makeTrie(Strings... strs)
  -> decltype(detail::makeTrie<0>(detail::nil(),strs...))
{ return {}; }

} // namespace CtTrie

#define TRIE(str)  CtTrie::doTrie((str),[&]{
#define CASE(str)  },CSTR(str),[&]{
#define ENDTRIE    })

#endif


#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>

#define XREP 256

// or:  typedef decltype(make_index_sequence<256>()) base_seq;
typedef index_sequence<
#define X(z,n,data) BOOST_PP_COMMA_IF(n) n                 // or: just use  X() n   +   BOOST_PP_ENUM(XREP,X,dummy)
  BOOST_PP_REPEAT(XREP,X,dummy)
#undef X
  > base_seq;

template <typename...> struct type_array {};

// requires TrieNode to multiple inherit all Transitions
template <int Char,typename Next>
constexpr Next select(Transition<Char,Next>)
{ return {}; }

template <int Char>
constexpr nil select(...)
{ return {}; }

template <typename TrieNode,unsigned int... Is>
constexpr auto mkidx(TrieNode trie,index_sequence<Is...>)
  -> type_array<decltype(select<Is>(trie))...>
{ return {}; }

// c++17: constexpr if
template <typename T> struct is_nil { static constexpr bool value = false; }; // ... : false_type
template <> struct is_nil<nil> { static constexpr bool value = true; }; // or: std::is_same

template <typename Stringview,typename FnE,typename... Fns> // never called, but must be instantiable ...
constexpr auto checkTrie(nil,Stringview&& str,FnE&& fne,Fns&&... fns)
  -> decltype(fne())
{
  return fne();
}

template <typename Stringview,
#define X(z,n,data) data ## n,
  BOOST_PP_REPEAT(XREP,X,typename A)
#undef X
  typename FnE,typename... Fns>
/*constexpr*/ auto Switch256(unsigned char ch,Stringview&& str,type_array<
#define X(z,n,data) BOOST_PP_COMMA_IF(n) data ## n
  BOOST_PP_REPEAT(XREP,X,A)
#undef X
  >,FnE&& fne,Fns&&... fns)
  -> decltype(fne())
{
  switch (ch) {
#define X(z,n,data) case n : if (is_nil<data ## n>::value) break; return checkTrie(data ## n (),(Stringview&&)str,(FnE&&)fne,(Fns&&)fns...);
  BOOST_PP_REPEAT(XREP,X,A)
#undef X
  }
  return fne();
}

template <typename Stringview,typename TrieNode,typename FnE,typename... Fns>
constexpr auto Switch(unsigned char ch,Stringview&& str,TrieNode trie,FnE&& fne,Fns&&... fns)
  -> decltype(fne())
{
  return Switch256(ch,(Stringview&&)str,mkidx(trie,base_seq()),(FnE&&)fne,(Fns&&)fns...);
}

#undef XREP



#define X16(p) \
  X(p,0) SEP X(p,1) SEP X(p,2) SEP X(p,3) SEP X(p,4) SEP X(p,5) SEP X(p,6) SEP X(p,7) SEP \
  X(p,8) SEP X(p,9) SEP X(p,a) SEP X(p,b) SEP X(p,c) SEP X(p,d) SEP X(p,e) SEP X(p,f)

#define XBLOCK \
  X16(0) SEP X16(1) SEP X16(2) SEP X16(3) SEP X16(4) SEP X16(5) SEP X16(6) SEP X16(7) SEP \
  X16(8) SEP X16(9) SEP X16(a) SEP X16(b) SEP X16(c) SEP X16(d) SEP X16(e) SEP X16(f)

// or:  typedef decltype(make_index_sequence<256>()) base_seq;
typedef index_sequence<
#define X(p,q) 0x ## p ## q
#define SEP ,
  XBLOCK
#undef SEP
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

template <typename T> struct is_nil { static constexpr bool value = false; }; // ... : false_type
template <> struct is_nil<nil> { static constexpr bool value = true; }; // or: std::is_same

// c++17: constexpr if
template <typename Stringview,typename FnE,typename... Fns> // never called, but must be instantiable ...
constexpr auto checkTrie(nil,Stringview&& str,FnE&& fne,Fns&&... fns)
  -> decltype(fne())
{
  return fne();
}

template <typename Stringview,
#define X(p,q) typename A ## p ## q
#define SEP ,
  XBLOCK,
#undef SEP
#undef X
  typename FnE,typename... Fns>
/*constexpr*/ auto Switch256(unsigned char ch,Stringview&& str,type_array<
#define X(p,q) A ## p ## q
#define SEP ,
  XBLOCK
#undef SEP
#undef X
  >,FnE&& fne,Fns&&... fns)
  -> decltype(fne())
{
  switch (ch) {
#define X(p,q) case 0x ## p ## q : if (is_nil<A ## p ## q>::value) break; return checkTrie(A ## p ## q(),(Stringview &&)str,(FnE&&)fne,(Fns&&)fns...);
#define SEP
    XBLOCK
#undef SEP
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

#undef X16
#undef XBLOCK


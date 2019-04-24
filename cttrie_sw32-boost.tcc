
#include <boost/preprocessor/iteration/local.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>

#define XSUB1(z,p,data) int Char ## p,typename Next ## p,
#define XSUB2(z,p,data) BOOST_PP_COMMA_IF(p) Transition<Char ## p,Next ## p>
#define XSUB3(z,p,data) case Char ## p: return checkTrie(Next ## p(),(Stringview&&)str,(FnE&&)fne,(Fns&&)fns...);

#define BOOST_PP_LOCAL_MACRO(n) \
  template <typename Stringview, \
    BOOST_PP_REPEAT(n,XSUB1,dummy) \
    typename FnE,typename... Fns> \
  auto Switch(unsigned char ch,Stringview&& str,TrieNode< \
    BOOST_PP_REPEAT(n,XSUB2,dummy) \
    >,FnE&& fne,Fns&&... fns) \
    -> decltype(fne()) \
  { \
    switch (ch) { \
      BOOST_PP_REPEAT(n,XSUB3,dummy) \
    } \
    return fne(); \
  }

#define BOOST_PP_LOCAL_LIMITS (2,32)
#include BOOST_PP_LOCAL_ITERATE()

#undef XSUB1
#undef XSUB2
#undef XSUB3



#define XTMPLATE \
  template < \
    XBLOCK(XSUB1,XCOMMA), \
    typename FnE,typename... Fns> \
  auto Switch(unsigned char ch,stringview str,TrieNode< \
    XBLOCK(XSUB2,XCOMMA) \
    >,FnE&& fne,Fns&&... fns) \
    -> decltype(fne()) \
  { \
    switch (ch) { \
      XBLOCK(XSUB3,XSEMIC); \
    } \
    return fne(); \
  }

#define XCOMMA() ,
#define XSEMIC() ;
#define XSUB1(p) int Char ## p,typename Next ## p
#define XSUB2(p) Transition<Char ## p,Next ## p>
#define XSUB3(p) case Char ## p: return checkTrie(Next ## p(),str,(FnE&&)fne,(Fns&&)fns...)

#define XCAT(x,p,q) x(p ## q)
#define XBLOCK0(p,x,sep) XCAT(x,p,0)
#define XBLOCK1(p,x,sep) XBLOCK0(p,x,sep) sep() XCAT(x,p,1)
#define XBLOCK2(p,x,sep) XBLOCK1(p,x,sep) sep() XCAT(x,p,2)
#define XBLOCK3(p,x,sep) XBLOCK2(p,x,sep) sep() XCAT(x,p,3)
#define XBLOCK4(p,x,sep) XBLOCK3(p,x,sep) sep() XCAT(x,p,4)
#define XBLOCK5(p,x,sep) XBLOCK4(p,x,sep) sep() XCAT(x,p,5)
#define XBLOCK6(p,x,sep) XBLOCK5(p,x,sep) sep() XCAT(x,p,6)
#define XBLOCK7(p,x,sep) XBLOCK6(p,x,sep) sep() XCAT(x,p,7)

#define XXBLOCK(x,sep)
#define XXNUM 0
/* unused
#define XBLOCK(x,sep) XXBLOCK(x,sep) XBLOCK0(XXNUM,x,sep)
XTMPLATE
#undef XBLOCK
*/
#define XBLOCK(x,sep) XXBLOCK(x,sep) XBLOCK1(XXNUM,x,sep)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) XXBLOCK(x,sep) XBLOCK2(XXNUM,x,sep)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) XXBLOCK(x,sep) XBLOCK3(XXNUM,x,sep)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) XXBLOCK(x,sep) XBLOCK4(XXNUM,x,sep)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) XXBLOCK(x,sep) XBLOCK5(XXNUM,x,sep)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) XXBLOCK(x,sep) XBLOCK6(XXNUM,x,sep)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) XXBLOCK(x,sep) XBLOCK7(XXNUM,x,sep)
XTMPLATE
#undef XBLOCK
#undef XXNUM
#undef XXBLOCK

#define XXBLOCK(x,sep) XBLOCK7(0,x,sep) sep()
#define XXNUM 1
#define XBLOCK(x,sep) XXBLOCK(x,sep) XBLOCK0(XXNUM,x,sep)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) XXBLOCK(x,sep) XBLOCK1(XXNUM,x,sep)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) XXBLOCK(x,sep) XBLOCK2(XXNUM,x,sep)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) XXBLOCK(x,sep) XBLOCK3(XXNUM,x,sep)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) XXBLOCK(x,sep) XBLOCK4(XXNUM,x,sep)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) XXBLOCK(x,sep) XBLOCK5(XXNUM,x,sep)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) XXBLOCK(x,sep) XBLOCK6(XXNUM,x,sep)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) XXBLOCK(x,sep) XBLOCK7(XXNUM,x,sep)
XTMPLATE
#undef XBLOCK
#undef XXNUM
#undef XXBLOCK

#define XXBLOCK(x,sep) XBLOCK7(0,x,sep) sep() XBLOCK7(1,x,sep) sep()
#define XXNUM 2
#define XBLOCK(x,sep) XXBLOCK(x,sep) XBLOCK0(XXNUM,x,sep)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) XXBLOCK(x,sep) XBLOCK1(XXNUM,x,sep)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) XXBLOCK(x,sep) XBLOCK2(XXNUM,x,sep)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) XXBLOCK(x,sep) XBLOCK3(XXNUM,x,sep)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) XXBLOCK(x,sep) XBLOCK4(XXNUM,x,sep)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) XXBLOCK(x,sep) XBLOCK5(XXNUM,x,sep)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) XXBLOCK(x,sep) XBLOCK6(XXNUM,x,sep)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) XXBLOCK(x,sep) XBLOCK7(XXNUM,x,sep)
XTMPLATE
#undef XBLOCK
#undef XXNUM
#undef XXBLOCK

#define XXBLOCK(x,sep) XBLOCK7(0,x,sep) sep() XBLOCK7(1,x,sep) sep() XBLOCK7(2,x,sep) sep()
#define XXNUM 3
#define XBLOCK(x,sep) XXBLOCK(x,sep) XBLOCK0(XXNUM,x,sep)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) XXBLOCK(x,sep) XBLOCK1(XXNUM,x,sep)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) XXBLOCK(x,sep) XBLOCK2(XXNUM,x,sep)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) XXBLOCK(x,sep) XBLOCK3(XXNUM,x,sep)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) XXBLOCK(x,sep) XBLOCK4(XXNUM,x,sep)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) XXBLOCK(x,sep) XBLOCK5(XXNUM,x,sep)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) XXBLOCK(x,sep) XBLOCK6(XXNUM,x,sep)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) XXBLOCK(x,sep) XBLOCK7(XXNUM,x,sep)
XTMPLATE
#undef XBLOCK
#undef XXNUM
#undef XXBLOCK

#undef XBLOCK7
#undef XBLOCK6
#undef XBLOCK5
#undef XBLOCK4
#undef XBLOCK3
#undef XBLOCK2
#undef XBLOCK1
#undef XBLOCK0
#undef XCAT

#undef XSUB3
#undef XSUB2
#undef XSUB1
#undef XSEMIC
#undef XCOMMA
#undef XTMPLATE


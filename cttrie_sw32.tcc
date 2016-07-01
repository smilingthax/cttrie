
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
      XBLOCK(XSUB3,;); \
    } \
    return fne(); \
  }

#define XCOMMA ,
#define XSUB1(p) int Char ## p,typename Next ## p
#define XSUB2(p) Transition<Char ## p,Next ## p>
#define XSUB3(p) case Char ## p: return checkTrie(Next ## p(),str,(FnE&&)fne,(Fns&&)fns...)

#define XBLOCK(x,sep) x(00) sep x(01)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) x(00) sep x(01) sep x(02)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) x(00) sep x(01) sep x(02) sep x(03)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) x(00) sep x(01) sep x(02) sep x(03) sep x(04)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) x(00) sep x(01) sep x(02) sep x(03) sep x(04) sep x(05)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) x(00) sep x(01) sep x(02) sep x(03) sep x(04) sep x(05) sep x(06)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) x(00) sep x(01) sep x(02) sep x(03) sep x(04) sep x(05) sep x(06) sep x(07)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) x(00) sep x(01) sep x(02) sep x(03) sep x(04) sep x(05) sep x(06) sep x(07) sep \
                      x(08)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) x(00) sep x(01) sep x(02) sep x(03) sep x(04) sep x(05) sep x(06) sep x(07) sep \
                      x(08) sep x(09)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) x(00) sep x(01) sep x(02) sep x(03) sep x(04) sep x(05) sep x(06) sep x(07) sep \
                      x(08) sep x(09) sep x(10)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) x(00) sep x(01) sep x(02) sep x(03) sep x(04) sep x(05) sep x(06) sep x(07) sep \
                      x(08) sep x(09) sep x(10) sep x(11)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) x(00) sep x(01) sep x(02) sep x(03) sep x(04) sep x(05) sep x(06) sep x(07) sep \
                      x(08) sep x(09) sep x(10) sep x(11) sep x(12)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) x(00) sep x(01) sep x(02) sep x(03) sep x(04) sep x(05) sep x(06) sep x(07) sep \
                      x(08) sep x(09) sep x(10) sep x(11) sep x(12) sep x(13)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) x(00) sep x(01) sep x(02) sep x(03) sep x(04) sep x(05) sep x(06) sep x(07) sep \
                      x(08) sep x(09) sep x(10) sep x(11) sep x(12) sep x(13) sep x(14)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) x(00) sep x(01) sep x(02) sep x(03) sep x(04) sep x(05) sep x(06) sep x(07) sep \
                      x(08) sep x(09) sep x(10) sep x(11) sep x(12) sep x(13) sep x(14) sep x(15)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) x(00) sep x(01) sep x(02) sep x(03) sep x(04) sep x(05) sep x(06) sep x(07) sep \
                      x(08) sep x(09) sep x(10) sep x(11) sep x(12) sep x(13) sep x(14) sep x(15) sep \
                      x(16)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) x(00) sep x(01) sep x(02) sep x(03) sep x(04) sep x(05) sep x(06) sep x(07) sep \
                      x(08) sep x(09) sep x(10) sep x(11) sep x(12) sep x(13) sep x(14) sep x(15) sep \
                      x(16) sep x(17)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) x(00) sep x(01) sep x(02) sep x(03) sep x(04) sep x(05) sep x(06) sep x(07) sep \
                      x(08) sep x(09) sep x(10) sep x(11) sep x(12) sep x(13) sep x(14) sep x(15) sep \
                      x(16) sep x(17) sep x(18)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) x(00) sep x(01) sep x(02) sep x(03) sep x(04) sep x(05) sep x(06) sep x(07) sep \
                      x(08) sep x(09) sep x(10) sep x(11) sep x(12) sep x(13) sep x(14) sep x(15) sep \
                      x(16) sep x(17) sep x(18) sep x(19)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) x(00) sep x(01) sep x(02) sep x(03) sep x(04) sep x(05) sep x(06) sep x(07) sep \
                      x(08) sep x(09) sep x(10) sep x(11) sep x(12) sep x(13) sep x(14) sep x(15) sep \
                      x(16) sep x(17) sep x(18) sep x(19) sep x(20)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) x(00) sep x(01) sep x(02) sep x(03) sep x(04) sep x(05) sep x(06) sep x(07) sep \
                      x(08) sep x(09) sep x(10) sep x(11) sep x(12) sep x(13) sep x(14) sep x(15) sep \
                      x(16) sep x(17) sep x(18) sep x(19) sep x(20) sep x(21)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) x(00) sep x(01) sep x(02) sep x(03) sep x(04) sep x(05) sep x(06) sep x(07) sep \
                      x(08) sep x(09) sep x(10) sep x(11) sep x(12) sep x(13) sep x(14) sep x(15) sep \
                      x(16) sep x(17) sep x(18) sep x(19) sep x(20) sep x(21) sep x(22)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) x(00) sep x(01) sep x(02) sep x(03) sep x(04) sep x(05) sep x(06) sep x(07) sep \
                      x(08) sep x(09) sep x(10) sep x(11) sep x(12) sep x(13) sep x(14) sep x(15) sep \
                      x(16) sep x(17) sep x(18) sep x(19) sep x(20) sep x(21) sep x(22) sep x(23)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) x(00) sep x(01) sep x(02) sep x(03) sep x(04) sep x(05) sep x(06) sep x(07) sep \
                      x(08) sep x(09) sep x(10) sep x(11) sep x(12) sep x(13) sep x(14) sep x(15) sep \
                      x(16) sep x(17) sep x(18) sep x(19) sep x(20) sep x(21) sep x(22) sep x(23) sep \
                      x(24)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) x(00) sep x(01) sep x(02) sep x(03) sep x(04) sep x(05) sep x(06) sep x(07) sep \
                      x(08) sep x(09) sep x(10) sep x(11) sep x(12) sep x(13) sep x(14) sep x(15) sep \
                      x(16) sep x(17) sep x(18) sep x(19) sep x(20) sep x(21) sep x(22) sep x(23) sep \
                      x(24) sep x(25)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) x(00) sep x(01) sep x(02) sep x(03) sep x(04) sep x(05) sep x(06) sep x(07) sep \
                      x(08) sep x(09) sep x(10) sep x(11) sep x(12) sep x(13) sep x(14) sep x(15) sep \
                      x(16) sep x(17) sep x(18) sep x(19) sep x(20) sep x(21) sep x(22) sep x(23) sep \
                      x(24) sep x(25) sep x(26)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) x(00) sep x(01) sep x(02) sep x(03) sep x(04) sep x(05) sep x(06) sep x(07) sep \
                      x(08) sep x(09) sep x(10) sep x(11) sep x(12) sep x(13) sep x(14) sep x(15) sep \
                      x(16) sep x(17) sep x(18) sep x(19) sep x(20) sep x(21) sep x(22) sep x(23) sep \
                      x(24) sep x(25) sep x(26) sep x(27)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) x(00) sep x(01) sep x(02) sep x(03) sep x(04) sep x(05) sep x(06) sep x(07) sep \
                      x(08) sep x(09) sep x(10) sep x(11) sep x(12) sep x(13) sep x(14) sep x(15) sep \
                      x(16) sep x(17) sep x(18) sep x(19) sep x(20) sep x(21) sep x(22) sep x(23) sep \
                      x(24) sep x(25) sep x(26) sep x(27) sep x(28)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) x(00) sep x(01) sep x(02) sep x(03) sep x(04) sep x(05) sep x(06) sep x(07) sep \
                      x(08) sep x(09) sep x(10) sep x(11) sep x(12) sep x(13) sep x(14) sep x(15) sep \
                      x(16) sep x(17) sep x(18) sep x(19) sep x(20) sep x(21) sep x(22) sep x(23) sep \
                      x(24) sep x(25) sep x(26) sep x(27) sep x(28) sep x(29)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) x(00) sep x(01) sep x(02) sep x(03) sep x(04) sep x(05) sep x(06) sep x(07) sep \
                      x(08) sep x(09) sep x(10) sep x(11) sep x(12) sep x(13) sep x(14) sep x(15) sep \
                      x(16) sep x(17) sep x(18) sep x(19) sep x(20) sep x(21) sep x(22) sep x(23) sep \
                      x(24) sep x(25) sep x(26) sep x(27) sep x(28) sep x(29) sep x(30)
XTMPLATE
#undef XBLOCK
#define XBLOCK(x,sep) x(00) sep x(01) sep x(02) sep x(03) sep x(04) sep x(05) sep x(06) sep x(07) sep \
                      x(08) sep x(09) sep x(10) sep x(11) sep x(12) sep x(13) sep x(14) sep x(15) sep \
                      x(16) sep x(17) sep x(18) sep x(19) sep x(20) sep x(21) sep x(22) sep x(23) sep \
                      x(24) sep x(25) sep x(26) sep x(27) sep x(28) sep x(29) sep x(30) sep x(31)
XTMPLATE
#undef XBLOCK

#undef XSUB3
#undef XSUB2
#undef XSUB1
#undef XCOMMA
#undef XTMPLATE


#ifndef _STRINGVIEW_H
#define _STRINGVIEW_H

#include <cstring>
#include <utility>

struct stringview {
  template <unsigned int N>
  constexpr stringview(const char (&ar)[N]) : begin(ar),size((ar[N-1]==0) ? N-1 : N) {}  // strips trailing \0     // implicit

  template <typename String,typename Sfinae=decltype(std::declval<String>().c_str(),std::declval<String>().size())>
  constexpr stringview(String&& str) : begin(str.c_str()),size(str.size()) {}

  stringview(const char *begin) : begin(begin),size(std::strlen(begin)) {}

  constexpr stringview(const char *begin,unsigned int size) : begin(begin),size(size) {}

  constexpr bool empty() const {
    return (size==0);
  }

  constexpr char operator*() const {
    // assert(!empty());  // or: throw ?
    return *begin;
  }

  constexpr stringview substr(unsigned int start) const {
    return { begin+start,
             (start<size) ? size-start : 0 };
  }

  // (not actually used by cttrie)
  constexpr stringview substr(unsigned int start,unsigned int len) const {
    return { begin+start,
             (start<size) ?
               (len<size-start) ? len : size-start
             : 0 };
  }

private:
  const char *begin;
  unsigned int size;
};

#endif

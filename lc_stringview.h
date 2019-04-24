#ifndef _LC_STRINGVIEW_H
#define _LC_STRINGVIEW_H

#include "stringview.h"
#include <cctype>

struct lc_stringview : public stringview {
  lc_stringview(const char *s) : stringview(s) {}
  constexpr lc_stringview(stringview &&s) : stringview(std::move(s)) {}

  char operator*() const {
    return std::tolower(stringview::operator*());
  }

  constexpr lc_stringview substr(unsigned int start) const {
    return stringview::substr(start);
  }
};

#endif

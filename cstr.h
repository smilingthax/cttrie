#ifndef _CSTR_H
#define _CSTR_H

// C++2x: std::fixed_string ?

template <unsigned char... Chars>
struct string_t {
  static constexpr unsigned int size() {
    return sizeof...(Chars);
  }
  static const char *data() {
    static constexpr const char data[]={Chars...};
    return data;
  }
};

namespace detail {
template <typename Str,unsigned int N,unsigned char... Chars>
struct make_string_t : make_string_t<Str,N-1,Str().chars[N-1],Chars...> {};

template <typename Str,unsigned char... Chars>
struct make_string_t<Str,0,Chars...> { typedef string_t<Chars...> type; };
} // namespace detail

#define CSTR(str) []{ \
    struct Str { const char *chars = str; }; \
    return typename ::detail::make_string_t<Str,sizeof(str)>::type(); \
  }()

#endif

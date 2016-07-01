#ifndef _GETINDEX_H
#define _GETINDEX_H

// provides  pack_tools::get_index<I>(Ts&&... ts)

// (similar to what  std::get<I>(std::make_tuple(ts...))  does)

namespace pack_tools {

namespace detail {
  template <unsigned int> struct int_c {};

  template <unsigned int I>
  constexpr void *get_index_impl(int_c<I>) // invalid index
  {
    return {};
  }

  template <typename T0,typename... Ts>
  constexpr T0&& get_index_impl(int_c<0>,T0&& t0,Ts&&... ts)
  {
    return (T0&&)t0;
  }

  template <unsigned int I,typename T0,typename... Ts>
  constexpr auto get_index_impl(int_c<I>,T0&& t0,Ts&&... ts)
    -> decltype(get_index_impl(int_c<I-1>(),(Ts&&)ts...))
  {
    return get_index_impl(int_c<I-1>(),(Ts&&)ts...);
  }
} // namespace detail

template <unsigned int I,typename... Ts>
constexpr auto get_index(Ts&&... ts)
  -> decltype(detail::get_index_impl(detail::int_c<I>(),(Ts&&)ts...))
{
  static_assert((I<sizeof...(Ts)),"Invalid Index");
  return detail::get_index_impl(detail::int_c<I>(),(Ts&&)ts...);
}

} // namespace pack_tools

#endif

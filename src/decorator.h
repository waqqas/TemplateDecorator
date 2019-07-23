#pragma once

template <typename T, typename D>
std::function<T> decorate_function(std::function<T> inner, std::function<D> decorator)
{
  std::function<T> pre = [&]() {
    if (decorator)
      decorator();
    if (inner)
      inner();
  };

  return pre;
}
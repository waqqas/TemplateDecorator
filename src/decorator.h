#pragma once

template <typename T, typename PRE>
std::function<T> decorate_function(std::function<T> inner, std::function<PRE> pre, std::function<PRE> post)
{
  return [&]() {
    if (pre)
      pre();
    if (inner)
      inner();
    if (post)
      post();
  };
}
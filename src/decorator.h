#pragma once

#include <functional>

template <typename T, typename PRE, typename POST>
std::function<T> decorate_function(std::function<T> inner, std::function<PRE> pre, std::function<POST> post)
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
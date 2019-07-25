#pragma once

#include <functional>
#include <type_traits>


template <typename T, typename PRE>
std::function<T> decorate_function(std::function<T> inner)
{
  return [&]() {
    if (inner)
      inner();
  };
}


template <typename T, typename PRE>
std::function<T> decorate_function(std::function<T> inner, 
std::function<PRE> pre)
{
  return [&]() {
    if (pre)
      pre();
    if (inner)
      inner();
  };
}


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

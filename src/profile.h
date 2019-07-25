#pragma once

#include <chrono>

namespace profiler {

class profile
{
public:
  using clock = std::chrono::steady_clock;

private:
  clock::time_point _start;
  clock::time_point _end;

public:
  void start(void)
  {
    _start = clock::now();
  }

  void end(void)
  {
    _end = clock::now();
  }

  clock::duration diff(void)
  {
    return (_end - _start);
  }

  template <typename T>
  std::function<T> profile_it(std::function<T> inner)
  {
    return [&]() {
      start();
      inner();
      end();
    };
  }
};
}  // namespace profiler

#pragma once

#include "foo.h"

template <typename T>
class decorator : public T
{
public:
  decorator(T &f)
    : f(f)
  {}
  virtual void do_work() override
  {
    // Do something else here to decorate
    // the do_work function
    f.do_work();
  }

private:
  T &f;
};

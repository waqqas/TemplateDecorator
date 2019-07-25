#include <functional>
#include <iostream>

#include "decorator.h"
#include "foo.h"
#include "profile.h"

int main(void)
{
  profiler::profile p;
  foo_concrete      f;

  std::function<void(void)> do_work = std::bind(&foo::do_work, f);

  std::function<void(void)> start = [&p]() { p.start(); };
  std::function<void(void)> end   = [&p]() { p.end(); };

  {
    auto decorated_do_work = decorate_function(do_work, start, end);
    decorated_do_work();

    std::cout << "diff " << p.diff().count() << std::endl;
  }

  {
    auto decorated_do_work = p.profile_it(do_work);
    decorated_do_work();
    std::cout << "diff " << p.diff().count() << std::endl;
  }

  return 0;
}

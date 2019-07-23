#include <functional>
#include <iostream>

#include "decorator.h"
#include "foo.h"

int main(void)
{
  std::function<void()> pre = []() { std::cout << "prefix" << std::endl; };
  foo_concrete          f;

  std::function<void(void)> do_work           = std::bind(&foo::do_work, f);
  auto                      decorated_do_work = decorate_function(do_work, pre);
  decorated_do_work();

  return 0;
}

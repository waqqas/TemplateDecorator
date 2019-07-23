#include <iostream>

#include "decorator.h"

void bar(foo &f)
{
  f.do_work();
}

int main(void)
{
  foo_concrete  f;
  decorator<foo_concrete> df{f};
  bar(df);
  return 0;
}

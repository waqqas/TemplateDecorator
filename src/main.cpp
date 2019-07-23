#include <iostream>

#include "decorator.h"

int main(void)
{
  foo_concrete  f;
  foo_decorator decorated_f{f};
  bar(decorated_f);
  return 0;
}

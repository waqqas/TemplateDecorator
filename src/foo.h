#pragma once

#include "iostream"

class foo
{
public:
  virtual void do_work() = 0;
};

class foo_concrete : public foo
{
public:
  virtual void do_work() override
  {
     std::cout << "foo_concrete: do_work()" << std::endl;
  }
};

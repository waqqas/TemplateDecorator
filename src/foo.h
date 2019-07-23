#pragma once

#include <chrono>
#include <iostream>
#include <thread>

class foo
{
public:
  virtual void do_work() = 0;
};

class foo_concrete : public foo
{
public:
  virtual void do_work(void) override
  {
    std::cout << "foo_concrete: do_work() start" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "foo_concrete: do_work() end" << std::endl;
  }
};

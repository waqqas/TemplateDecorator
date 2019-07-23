#pragma once
class foo
{
  public:
    virtual void do_work() = 0;
};
class foo_concrete : public foo
{
  public:
    virtual void do_work() override
    { }
};
class foo_decorator : public foo
{
  public:
    foo_decorator(foo& f)
      : f(f)
    { }
    virtual void do_work() override
    {
      // Do something else here to decorate
      // the do_work function
      f.do_work();
    }
  private:
    foo& f;
};
void bar(foo& f)
{
  f.do_work();
}

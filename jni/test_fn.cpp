extern "C" void impl(int *pi);

extern "C" void work()
{
  int i = 10;
  impl(&i);
}

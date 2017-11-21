#include <stdexcept>
#include <string>

extern void impl(const char*& bytes, const char * const end);

void work(const std::string &data)
{
  const char *d = data.data();
  return impl(d, data.data() + data.size());
}



#include <stdexcept>
#include <string>
#include <cstdio>

/**
 * The function with the faulty EH table encoding.
 *
 * To aid analysis, it is in a different translation unit to avoid
 * inlining and to permit different compiler options to be used for this
 * function only.
 */
extern void work(const std::string &data);

void
impl(const char*& bytes, const char * const end)
{
  std::printf("bytes: %02x%02x\n", unsigned(bytes[0]), unsigned(bytes[1]));
  if(bytes[0] != '\x80' || bytes[1] != '\x80') {
    std::puts("$$$$$$$$$$$$$$$$ FAILED");
  }
  throw std::runtime_error{""};
}

int main()
{
  try {
    work(std::string("\x80\x80", 2));
  } catch(std::runtime_error&){
    std::puts("expected1");
  }
  try {
    work(std::string("\x80\x80", 2));
  } catch(std::runtime_error&){
    std::puts("expected2");
  } 
}

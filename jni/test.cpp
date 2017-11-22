#include <stdio.h>

int g_counter;

/**
 * The function with the faulty EH table encoding.
 *
 * To aid analysis, it is in a different translation unit to avoid
 * inlining and to permit different compiler options to be used for this
 * function only.
 */
extern "C" void work();

extern "C" void impl(int *pi)
{
  throw 20;
}

int main()
{
  int val1 = ++g_counter;
  try {
    work();
  } catch(int){
  }
  int val2 = ++g_counter;
  try {
    work();
  } catch(int){
  }
  if (val1 != 1 || val2 != 2) {
    printf("ERROR: (%d, %d) != (1, 2)\n", val1, val2);
  } else {
    printf("SUCCESS\n");
  }
}

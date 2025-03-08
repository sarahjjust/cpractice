#include <stdio.h>

int main(void)
{
  float a = 0.0012345;
  float *p = &a;
  int *q = (int *)p;
  printf("%.7f, %d\n", a, *q);
}

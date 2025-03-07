#include <stdio.h>

struct point {
  int x;
  int y;
};

struct point add(struct point a, struct point b) {
  struct point result;
  result.x = a.x + b.x;
  result.y = a.y + b.y;
  return result;
}

int main(void) {
  struct point a;
  a.x = 2;
  a.y = 3;
  struct point b = {.x = 3, .y = 2};
  struct point c = add(a, b);
  printf("(%d, %d)\n", c.x, c.y);

  return 0;
}

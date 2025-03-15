#include <stdlib.h>
#include <unistd.h>

#include "circle.h"

static int DIMX = 50;
static int DIMY = 50;

struct circle {
  int x;
  int y;
  int r;
  char c;
};

struct circleNode {
  struct circle cir;
  int age;
  struct circleNode *next;
};

int add(struct circleNode **list, int x, int y, int r, char c)
{
  struct circleNode *newNode = malloc(sizeof(struct circleNode));
  if (newNode == NULL) return 1;
  newNode->cir.x = x;
  newNode->cir.y = y;
  newNode->cir.r = r;
  newNode->cir.c = c;
  newNode->age = 0;
  newNode->next = NULL;

  if (*list == NULL) {
    *list = newNode;
    return 0;
  }

  struct circleNode *listp = *list;
  while (listp->next != NULL) {
    listp = listp->next;
  }
  listp->next = newNode;
  return 0;
}

int pop(struct circleNode **list)
{
  if (*list == NULL) return 1;
  struct circleNode *next = (*list)->next;
  free(*list);
  *list = next;
  return 0;
}

void freeList(struct circleNode *list)
{
  while (list != NULL) {
    struct circleNode *next = list->next;
    free(list);
    list = next;
  }
}

int lenList(struct circleNode *list)
{
  int count = 0;
  while (list != NULL) {
    count++;
    list = list->next;
  }
  return count;
}

int init()
{
  initscr();
  cbreak();
  noecho();
  curs_set(0);
  clear();
  refresh();

  return 0;
}

void draw(int x, int y, char c, int dimX, int dimY)
{
  if (x >= 0 && x < dimX && y >= 0 && y < dimY) {
    move(y, x);
    addch(c);
  }
}

int drawCircle(int rad, int cenX, int cenY, char c, int dimX, int dimY)
{
  if (rad < 1) {
    draw(cenX, cenY, c, dimX, dimY);
    return 0;
  }

  int x = 0;
  int y = -1 * rad;
  while (x <= -1 * y) {
    draw(cenX + x, cenY + y, c, dimX, dimY);
    draw(cenX - x, cenY + y, c, dimX, dimY);
    draw(cenX + x, cenY - y, c, dimX, dimY);
    draw(cenX - x, cenY - y, c, dimX, dimY);
    draw(cenX + y, cenY + x, c, dimX, dimY);
    draw(cenX - y, cenY + x, c, dimX, dimY);
    draw(cenX + y, cenY - x, c, dimX, dimY);
    draw(cenX - y, cenY - x, c, dimX, dimY);

    double checkY = y + 0.5;
    double a2 = (x + 1) * (x + 1);
    double b2 = (checkY) * (checkY);
    double c2 = rad * rad;
    if (a2 + b2 > c2) {
      y++;
    }
    x++;
  }

  return 0;
}

void drawList(struct circleNode *list, int dimX, int dimY)
{
  struct circleNode *curr = list;
  while (curr != NULL) {
    drawCircle(curr->cir.r, curr->cir.x, curr->cir.y, curr->cir.c, dimX, dimY);
    curr = curr->next;
  }
}

void eraseList(struct circleNode *list, int dimX, int dimY)
{
  struct circleNode *curr = list;
  while (curr != NULL) {
    drawCircle(curr->cir.r, curr->cir.x, curr->cir.y, ' ', dimX, dimY);
    curr->cir.r++;
    curr->age++;
    curr = curr->next;
  }
}

void drawCount(struct circleNode *list)
{
  int count = lenList(list);
  int x = DIMX + 5;
  while (count > 0) {
    move(x, 1);
    addch('0' + count % 10);
    count = count / 10;
    x--;
  }
}

int main()
{
  init();

  struct circleNode *list = NULL;

  while(1) {
    add(&list, rand() % DIMX, rand() % DIMY, 0, '@');
    for (int i = 0; i < 20; i++) {
      eraseList(list, DIMX, DIMY);
      drawList(list, DIMX, DIMY);
      drawCount(list);
      refresh();
      usleep(50000);
    }
    while(list != NULL && list->age > 1 * DIMX && list->age > 1 * DIMY) {
      pop(&list);
    }
  }
}

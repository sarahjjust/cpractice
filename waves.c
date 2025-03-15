#include <ncurses.h>
#include <unistd.h>

void drawVertLine(int i, char c)
{
  for (int j = 0; j < 10; j++) {
    move(j, i);
    addch(c);
  }
}

int main()
{
  initscr();
  cbreak();
  noecho();
  curs_set(0);
  clear();
  refresh();

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 20; j++) {
       move(i, j);
       addch('.');
    }
  }

  refresh();

  while(1)
  {
    for (int i = -1; i < 22; i++) {
      if (i < 19) {
        drawVertLine(i+1, 'o');
      }
      if (i >= 0 && i < 20) {
        drawVertLine(i, 'O');
      }
      if (i >= 1 && i < 21) {
        drawVertLine(i-1, 'o');
      }
      if (i >= 2) {
        drawVertLine(i-2, '.');
      }

      refresh();
      usleep(50000);
    }

    usleep(1000000);
  }
}

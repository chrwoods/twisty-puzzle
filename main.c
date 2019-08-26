#define SIZE 3

#include <stdio.h>
#include "cube.h"
#include "turn.c"
#include "maps.h"
#include "display.c"

void init_cube(cube* puzzle) {
  for(int i = 0; i < SIZE; i++) {
    for(int j = 0; j < SIZE; j++) {
      puzzle->up[i][j] = 1;
      puzzle->left[i][j] = 2;
      puzzle->front[i][j] = 3;
      puzzle->right[i][j] = 4;
      puzzle->back[i][j] = 5;
      puzzle->down[i][j] = 6;
    }
  }
}

int main(int argc, char *argv[]) {
  cube puzzle;
  init_cube(&puzzle);
  init_curses();
  char ch = getch();
  while(ch != 'q') {
    if(ch == 'f') {
      turn_front(&puzzle, 1);
    } else if(ch == 'b') {
      turn_back(&puzzle, 1);
    } else if(ch == 'r') {
      turn_right(&puzzle, 1);
    } else if(ch == 'l') {
      turn_left(&puzzle, 1);
    } else if(ch == 'u') {
      turn_up(&puzzle, 1);
    } else if(ch == 'd') {
      turn_down(&puzzle, 1);
    } else if(ch == 'x') {
      turn_x(&puzzle, 1);
    }
    update_cube_from_map(puzzle, map_1, 2, 0, 1);
    ch = getch();
  }
  you_meddling_kids();
  return 0;
}

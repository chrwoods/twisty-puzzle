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
  print_cube_from_map(puzzle, map_1, 1, 0);
  turn_front(&puzzle, 1);
  print_cube_from_map(puzzle, map_1, 2, 0);
  turn_back(&puzzle, 0);
  print_cube_from_map(puzzle, map_1, 2, 1);
  return 0;
}

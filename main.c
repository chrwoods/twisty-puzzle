#define SIZE 3

#include <stdio.h>
#include "cube.h"
#include "turn.c"

int main(int argc, char *argv[]) {
  short face[SIZE][SIZE] = {{0, 1, 2},
			    {3, 4, 5},
			    {6, 7, 8}};
  
  for(int n = 0; n < 3; n++) {
    for(int i = 0; i < SIZE; i++) {
      for(int j = 0; j < SIZE; j++) {
	printf("%d", face[i][j]);
      }
      printf("\n");
    }
    rotate_face(face, 1);
  }

  return 0;
}

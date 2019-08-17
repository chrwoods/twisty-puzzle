void rotate_face(short face[SIZE][SIZE], short clockwise) {
  short rotated[SIZE][SIZE];
  for(int i = 0; i < SIZE; i++) {
    for(int j = 0; j < SIZE; j++) {
      if(clockwise) {
	rotated[j][SIZE - 1 - i] = face[i][j];
      } else {
	rotated[i][j] = face[j][SIZE - 1 - i];
      }
    }
  }
  for(int i = 0; i < SIZE; i++) {
    for(int j = 0; j < SIZE; j++) {
      face[i][j] = rotated[i][j];
    }
  }
}

void turn_front(cube puzzle, short clockwise) {
  rotate_face(puzzle.front, clockwise);
  for(int i = 0; i < SIZE; i++) {
    short temp = cube.up[SIZE - 1][i];
    if(clockwise) {
      cube.up[SIZE - 1][i] = cube.left[SIZE - 1 - i][SIZE - 1];
      cube.left[SIZE - 1 - i][SIZE - 1] = cube.down[0][SIZE - 1 - i];
      cube.down[0][SIZE - 1 - i] = cube.right[i][0];
      cube.right[i][0] = temp;
    } else {
      cube.up[SIZE - 1][i] = cube.right[i][0];
      cube.right[i][0] = cube.down[0][SIZE - 1 - i];
      cube.down[0][SIZE - 1 - i] = cube.left[SIZE - 1 - i][SIZE - 1];
      cube.left[SIZE - 1 - i][SIZE - 1] = temp;
    }
  }
}

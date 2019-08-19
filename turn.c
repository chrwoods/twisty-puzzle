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

void turn_front(cube* puzzle, short clockwise) {
  rotate_face(puzzle->front, clockwise);
  for(int i = 0; i < SIZE; i++) {
    short temp = puzzle->up[SIZE - 1][i];
    if(clockwise) {
      puzzle->up[SIZE - 1][i] = puzzle->left[SIZE - 1 - i][SIZE - 1];
      puzzle->left[SIZE - 1 - i][SIZE - 1] = puzzle->down[0][SIZE - 1 - i];
      puzzle->down[0][SIZE - 1 - i] = puzzle->right[i][0];
      puzzle->right[i][0] = temp;
    } else {
      puzzle->up[SIZE - 1][i] = puzzle->right[i][0];
      puzzle->right[i][0] = puzzle->down[0][SIZE - 1 - i];
      puzzle->down[0][SIZE - 1 - i] = puzzle->left[SIZE - 1 - i][SIZE - 1];
      puzzle->left[SIZE - 1 - i][SIZE - 1] = temp;
    }
  }
}

void turn_back(cube* puzzle, short clockwise) {
  rotate_face(puzzle->back, clockwise);
  for(int i = 0; i < SIZE; i++) {
    short temp = puzzle->up[0][SIZE - 1 - i];
    if(clockwise) {
      puzzle->up[0][SIZE - 1 - i] = puzzle->right[SIZE - 1 - i][SIZE - 1];
      puzzle->right[SIZE - 1 - i][SIZE - 1] = puzzle->down[SIZE - 1][i];
      puzzle->down[SIZE - 1][i] = puzzle->left[i][0];
      puzzle->left[i][0] = temp;
    } else {
      puzzle->up[0][SIZE - 1 - i] = puzzle->left[i][0];
      puzzle->left[i][0] = puzzle->down[SIZE - 1][i];
      puzzle->down[SIZE - 1][i] = puzzle->right[SIZE - 1 - i][SIZE - 1];
      puzzle->right[SIZE - 1 - i][SIZE - 1] = temp;
    }
  }
}

void turn_right(cube* puzzle, short clockwise) {
  rotate_face(puzzle->right, clockwise);
  for(int i = 0; i < SIZE; i++) {
    short temp = puzzle->front[SIZE - 1 - i][SIZE - 1];
    if(clockwise) {
      puzzle->front[SIZE - 1 - i][SIZE - 1] = puzzle->down[SIZE - 1 - i][SIZE - 1];
      puzzle->down[SIZE - 1 - i][SIZE - 1] = puzzle->back[i][0];
      puzzle->back[i][0] = puzzle->up[SIZE - 1 - i][SIZE - 1];
      puzzle->up[SIZE - 1 - i][SIZE - 1] = temp;
    } else {
      puzzle->front[SIZE - 1 - i][SIZE - 1] = puzzle->up[SIZE - 1 - i][SIZE - 1];
      puzzle->up[SIZE - 1 - i][SIZE - 1] = puzzle->back[i][0];
      puzzle->back[i][0] = puzzle->down[SIZE - 1 - i][SIZE - 1];
      puzzle->down[SIZE - 1 - i][SIZE - 1] = temp;
    }
  }
}

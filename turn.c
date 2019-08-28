#include <string.h>

short not(short num) {
  return num ? 0 : 1;
}

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

void turn_left(cube* puzzle, short clockwise) {
  rotate_face(puzzle->left, clockwise);
  for(int i = 0; i < SIZE; i++) {
    short temp = puzzle->up[i][0];
    if(clockwise) {
      puzzle->up[i][0] = puzzle->back[SIZE - 1 - i][SIZE - 1];
      puzzle->back[SIZE - 1 - i][SIZE - 1] = puzzle->down[i][0];
      puzzle->down[i][0] = puzzle->front[i][0];
      puzzle->front[i][0] = temp;
    } else { 
      puzzle->up[i][0] = puzzle->front[i][0];
      puzzle->front[i][0] = puzzle->down[i][0];
      puzzle->down[i][0] = puzzle->back[SIZE - 1 - i][SIZE - 1];
      puzzle->back[SIZE - 1 - i][SIZE - 1] = temp;
    }
  }
}

void turn_up(cube* puzzle, short clockwise) {
  rotate_face(puzzle->up, clockwise);
  for(int i = 0; i < SIZE; i++) {
    short temp = puzzle->front[0][i];
    if(clockwise) {
      puzzle->front[0][i] = puzzle->right[0][i];
      puzzle->right[0][i] = puzzle->back[0][i];
      puzzle->back[0][i] = puzzle->left[0][i];
      puzzle->left[0][i] = temp;
    } else {
      puzzle->front[0][i] = puzzle->left[0][i];
      puzzle->left[0][i] = puzzle->back[0][i];
      puzzle->back[0][i] = puzzle->right[0][i];
      puzzle->right[0][i] = temp;
    }
  }
}
    
void turn_down(cube* puzzle, short clockwise) {
  rotate_face(puzzle->down, clockwise);
  for(int i = 0; i < SIZE; i++) {
    short temp = puzzle->front[SIZE - 1][i];
    if(clockwise) {
      puzzle->front[SIZE - 1][i] = puzzle->left[SIZE - 1][i];
      puzzle->left[SIZE - 1][i] = puzzle->back[SIZE - 1][i];
      puzzle->back[SIZE - 1][i] = puzzle->right[SIZE - 1][i];
      puzzle->right[SIZE - 1][i] = temp;
    } else {
      puzzle->front[SIZE - 1][i] = puzzle->right[SIZE - 1][i];
      puzzle->right[SIZE - 1][i] = puzzle->back[SIZE - 1][i];
      puzzle->back[SIZE - 1][i] = puzzle->left[SIZE - 1][i];
      puzzle->left[SIZE - 1][i] = temp;
    }
  }
}

void turn_x(cube* puzzle, short clockwise) {
  rotate_face(puzzle->right, clockwise);
  rotate_face(puzzle->left, not(clockwise));
  for(int i = 0; i < SIZE; i++) {
    for(int j = 0; j < SIZE; j++) {
      short temp = puzzle->front[i][j];
      if(clockwise) {
	puzzle->front[i][j] = puzzle->down[i][j];
	puzzle->down[i][j] = puzzle->back[SIZE - 1 - i][SIZE - 1 - j];
	puzzle->back[SIZE - 1 - i][SIZE - 1 - j] = puzzle->up[i][j];
	puzzle->up[i][j] = temp;
      } else {
	puzzle->front[i][j] = puzzle->up[i][j];
	puzzle->up[i][j] = puzzle->back[SIZE - 1 - i][SIZE - 1 - j];
	puzzle->back[SIZE - 1 - i][SIZE - 1 - j] = puzzle->down[i][j];
	puzzle->down[i][j] = temp;
      }
    }
  }
}

void turn_y(cube* puzzle, short clockwise) {
  rotate_face(puzzle->up, clockwise);
  rotate_face(puzzle->down, not(clockwise));
  short temp[SIZE][SIZE];
  memcpy(temp, puzzle->front, sizeof(temp));
  if(clockwise) {
    memcpy(puzzle->front, puzzle->right, sizeof(temp));
    memcpy(puzzle->right, puzzle->back, sizeof(temp));
    memcpy(puzzle->back, puzzle->left, sizeof(temp));
    memcpy(puzzle->left, temp, sizeof(temp));
  } else {
    memcpy(puzzle->front, puzzle->left, sizeof(temp));
    memcpy(puzzle->left, puzzle->back, sizeof(temp));
    memcpy(puzzle->back, puzzle->right, sizeof(temp));
    memcpy(puzzle->right, temp, sizeof(temp));
  }
}

void turn_z(cube* puzzle, short clockwise) {
  rotate_face(puzzle->front, clockwise);
  rotate_face(puzzle->back, not(clockwise));
  for(int i = 0; i < SIZE; i++) {
    for(int j = 0; j < SIZE; j++) {
      short temp = puzzle->up[i][j];
      if(clockwise) {
	puzzle->up[i][j] = puzzle->left[SIZE - 1 - j][i];
	puzzle->left[SIZE - 1 - j][i] = puzzle->down[SIZE - 1 - i][SIZE - 1 - j];
	puzzle->down[SIZE - 1 - i][SIZE - 1 - j] = puzzle->right[j][SIZE - 1 - i];
	puzzle->right[j][SIZE - 1 - i] = temp;
      } else {
	puzzle->up[i][j] = puzzle->right[j][SIZE - 1 - i];
	puzzle->right[j][SIZE - 1 - i] = puzzle->down[SIZE - 1 - i][SIZE - 1 - j];
	puzzle->down[SIZE - 1 - i][SIZE - 1 - j] = puzzle->left[SIZE - 1 - j][i];
	puzzle->left[SIZE - 1 - j][i] = temp;
      }
    }
  }
}

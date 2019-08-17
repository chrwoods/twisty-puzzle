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

void rotate_face(short face[SIZE][SIZE]) {
  short rotated[SIZE][SIZE];
  for(int i = 0; i < SIZE; i++) {
    for(int j = 0; j < SIZE; j++) {
      rotated[j][SIZE - 1 - i] = face[i][j];
    }
  }
  for(int i = 0; i < SIZE; i++) {
    for(int j = 0; j < SIZE; j++) {
      face[i][j] = rotated[i][j];
    }
  }
}

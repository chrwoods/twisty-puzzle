short get_cell(cube puzzle, int row, int col, short num) {
  if(num == 0) return 0;
  if(num < 1 || num > 24) num %= 24;
  if(num < 0) num += 24;
  num--;

  short orientation = num / 6;
  short face = num % 6;
  int t_row;
  int t_col;

  if(orientation == 1) {
    t_row = SIZE - 1 - col;
    t_col = row;
  } else if(orientation == 2) {
    t_row = SIZE - 1 - row;
    t_col = SIZE - 1 - col;
  } else if(orientation == 3) {
    t_row = col;
    t_col = SIZE - 1 - row;
  } else {
    t_row = row;
    t_col = col;
  }

  switch(face) {
  case 0:
    return cube.up[t_row][t_col];
  case 1:
    return cube.left[t_row][t_col];
  case 2:
    return cube.front[t_row][t_col];
  case 3:
    return cube.right[t_row][t_col];
  case 4:
    return cube.back[t_row][t_col];
  default:
    return cube.down[t_row][t_col];
  }
}

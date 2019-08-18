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
    return puzzle.up[t_row][t_col];
  case 1:
    return puzzle.left[t_row][t_col];
  case 2:
    return puzzle.front[t_row][t_col];
  case 3:
    return puzzle.right[t_row][t_col];
  case 4:
    return puzzle.back[t_row][t_col];
  default:
    return puzzle.down[t_row][t_col];
  }
}

char get_char(short cell) {
  switch(cell) {
  case 1:
    return 'W';
  case 2:
    return 'B';
  case 3:
    return 'R';
  case 4:
    return 'G';
  case 5:
    return 'O';
  case 6:
    return 'Y';
  default:
    return ' ';
  }
}

void print_cube_from_map(cube puzzle, short map[3][4], short zoom) {
  for(int r = 0; r < 3; r++) {
    for(int c = 0; c < 4; c++) {
      for(int s = 0; s < SIZE; s++) {
	for(int z = 0; z < zoom; z++) {
	  for(int s2 = 0; s2 < SIZE; s2++) {
	    char color = get_char(get_cell(puzzle, s, s2, map[r][c]));
	    for(int z2; z2 < zoom; z2++) {
	      printf("%c", color);
	    }
	  }
	  printf("\n");
	}
      }
    }
  }
}
	  

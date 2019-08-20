#include <curses.h>

#define WHITE_PAIR 1
#define GREEN_PAIR 2
#define RED_PAIR 3
#define BLUE_PAIR 4
#define ORANGE_PAIR 5
#define YELLOW_PAIR 6

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
    return 'G';
  case 3:
    return 'R';
  case 4:
    return 'B';
  case 5:
    return 'O';
  case 6:
    return 'Y';
  default:
    return ' ';
  }
}

void print_cube_from_map(cube puzzle, const short map[3][4], short zoom, short spacing) {
  for(int r = 0; r < 3; r++) {
    for(int s = 0; s < SIZE; s++) {
      for(int z = 0; z < zoom; z++) {
	for(int c = 0; c < 4; c++) {
	  for(int s2 = 0; s2 < SIZE; s2++) {
	    char color = get_char(get_cell(puzzle, s, s2, map[r][c]));	  
	    for(int sp = 0; sp < spacing; sp++) {
	      printf(" ");
	    }
	    for(int z2 = 0; z2 < zoom; z2++) {
	      printf("%c", color);
	    }
	  }
	}
	printf("\n");
      }
      for(int sp = 0; sp < spacing; sp++) {
	printf("\n");
      }
    }
  }
}
	  
void init_curses() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  curs_set(FALSE);
  nodelay(stdscr, TRUE);
  if(has_colors()) start_color();
  init_pair(WHITE_PAIR, COLOR_WHITE, COLOR_BLACK);
  init_pair(BLUE_PAIR, COLOR_BLUE, COLOR_BLACK);
  init_pair(RED_PAIR, COLOR_RED, COLOR_BLACK);
  init_pair(GREEN_PAIR, COLOR_GREEN, COLOR_BLACK);
  init_pair(ORANGE_PAIR, COLOR_YELLOW, COLOR_BLACK);
  init_pair(YELLOW_PAIR, COLOR_YELLOW, COLOR_BLACK);
}

void you_meddling_kids() {
  endwin();
}

void update_cube_from_map(cube puzzle, const short map[3][4], short zoom, short spacing, short face_spacing) {
  short row = 0;
  short col = 0;
  for(int r = 0; r < 3; r++) {
    row += face_spacing;
    for(int s = 0; s < SIZE; s++) {
      for(int z = 0; z < zoom; z++) {
	for(int c = 0; c < 4; c++) {
	  col += face_spacing;
	  for(int s2 = 0; s2 < SIZE; s2++) {
	    for(int sp = 0; sp < spacing; sp++) {
	      mvaddch(row, col++, ' ');
	    }
	    int color = get_cell(puzzle, s, s2, map[r][c]);
	    if(color) {
	      attron(COLOR_PAIR(color));
	      if(color == WHITE_PAIR || color == YELLOW_PAIR) {
		attron(A_BOLD);
	      }
	      for(int z2 = 0; z2 < zoom; z2++) {
		mvaddch(row, col++, '#');
	      }
	      if(color == WHITE_PAIR || color == YELLOW_PAIR) {
		attroff(A_BOLD);
	      }
	      attroff(COLOR_PAIR(color));
	    } else {
	      col += zoom;
	    }
	  }
	}
	row++;
	col = 0;
      }
      row += spacing;
    }
  }
  refresh();
}

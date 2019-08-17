#define SIZE 3;

typedef struct cube {
  int[SIZE][SIZE] front;
  int[SIZE][SIZE] up;
  int[SIZE][SIZE] right;
  int[SIZE][SIZE] down;
  int[SIZE][SIZE] left;
  int[SIZE][SIZE] back;
} cube;

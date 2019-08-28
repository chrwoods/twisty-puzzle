DEPS = cube.h maps.h turn.c display.c

FLAGS = -lncurses

CC = gcc

twisty: main.c $(DEPS)
	$(CC) main.c -o twisty $(FLAGS)

clean:
	rm -f a.out twisty *~

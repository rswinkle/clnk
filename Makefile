
FLAGS=-std=c99

clnk: clnk.c
	$(CC) $(FLAGS) -o clnk main.c -Wall -Wextra -pedantic-errors -Wstrict-prototypes

clean:
	rm clnk

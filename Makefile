
# need the O1 to get -Wunused-result
FLAGS=-std=c99 -O1 -Wall -Wextra -pedantic-errors -Wstrict-prototypes

clnk: main.c clnk.h
	$(CC) $(FLAGS) -o clnk main.c

clean:
	rm clnk

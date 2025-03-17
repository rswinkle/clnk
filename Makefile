
# need the O1 to get -Wunused-result
FLAGS=-std=c99 -O1 -Wall -Wextra -pedantic-errors -Wstrict-prototypes
CXXFLAGS=-std=c++98 -O1 -Wall -Wextra -pedantic-errors

ALL: clnk clnk_cpp

clnk: main.c clnk.h
	$(CC) $(FLAGS) -o $@ main.c

clnk_cpp: main.cpp clnk.h
	$(CXX) $(CXXFLAGS) -o $@ main.cpp

clean:
	rm clnk clnk_cpp

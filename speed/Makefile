CC = cc
CFLAGS = -std=c99 -pedantic -Wall -Wextra

clean:
	rm -f bin/states

states: clean
	mkdir -p bin
	$(CC) ${CFLAGS} -g -o bin/$@ states.c

C_CC = cc
C_COPTS = -std=c99 -pedantic
C_SRC = c/cgol.c

cgol: c_cgol

debug: c_debug

c_cgol: clean
	$(C_CC) ${C_COPTS} -Os -o bin/$@ ${C_SRC}

c_debug: clean
	$(CC) ${C_COPTS} -g -o bin/c_cgol ${C_SRC} -Wall -Wextra

clean:
	rm -f bin/*


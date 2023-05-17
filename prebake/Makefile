CC = cc
CFLAGS = -std=c99 -pedantic -g
COMPTIME_H = comptime.h

clean:
	rm -f target/*

bake_values.c:
	$(CC) djb2.c bakery.c $@ -o target/bake_values -Wall -Wextra ${CFLAGS}

bake_constants: clean bake_values.c
	./target/bake_values > target/${COMPTIME_H}

smng.c: bake_constants
	$(CC) djb2.c $@ -o target/smng -Wall -Wextra ${CFLAGS}

build: smng.c

.PHONY: build clean bake_constants

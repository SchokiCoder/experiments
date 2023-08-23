CC=cc
CFLAGS=-std=c99 -pedantic -Wall -Wextra -g

all: target/smng

target/smng: smng.c djb2.c target/comptime.h
	$(CC) $(CFLAGS) -o $@ djb2.c $<

target/bake_values: bake_values.c djb2.c bakery.c
	$(CC) $(CFLAGS) -o $@ $^

target/comptime.h: target/bake_values
	./$< > $@

clean:
	rm -f target/*

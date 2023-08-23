CC=cc
CFLAGS=-std=c99 -pedantic -Wall -Wextra -g
LFLAGS=-I .

all: target/basics target/multdim_arrays target/nested_pointers

target/basics: tests/basics.c
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ $^

target/multdim_arrays: tests/multdim_arrays.c
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ $^

target/nested_pointers: tests/nested_pointers.c
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ $^

clean:
	rm -f target/*

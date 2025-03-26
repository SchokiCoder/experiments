CC=cc
CFLAGS=-std=c99 -pedantic -Wall -Wextra -g -fsanitize=address,undefined
LFLAGS=-I .

.PHONY: clean test

clean:
	rm -f target/*

target/basics: tests/basics.c trashbag.h
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ $<

target/multdim_arrays: tests/multdim_arrays.c trashbag.h
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ $<

target/nested_pointers: tests/nested_pointers.c trashbag.h
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ $<

test: target/basics target/multdim_arrays target/nested_pointers
	target/basics
	target/multdim_arrays
	target/nested_pointers

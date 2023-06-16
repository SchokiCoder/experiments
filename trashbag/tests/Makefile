CC=cc
CFLAGS=-std=c99 -Wall -Wextra -Werror -g
LFLAGS=-I ..
TARGET_PATH=../target

all: basics multdim_arrays nested_pointers

basics:
	$(CC) ${CFLAGS} ${LFLAGS} -o ${TARGET_PATH}/$@ $@.c

multdim_arrays:
	$(CC) ${CFLAGS} ${LFLAGS} -o ${TARGET_PATH}/$@ $@.c

nested_pointers:
	$(CC) ${CFLAGS} ${LFLAGS} -o ${TARGET_PATH}/$@ $@.c

clean:
	rm -f ${TARGET_PATH}/*

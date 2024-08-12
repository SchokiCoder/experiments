CC     :=cc
CFLAGS :=-std=c99 -pedantic -Wall -Wextra -g #-fsanitize=address,undefined <- currently causes segfaults in every ~5th run

COMPTIME_C_FILES :=comptime.c cgen.c djb2.c
SMNG_C_FILES     :=smng.c djb2.c

.PHONY: clean

smng: $(SMNG_C_FILES) pregen.h
	$(CC) $(CFLAGS) -o $@ $(SMNG_C_FILES)

comptime: $(COMPTIME_C_FILES) cgen.h
	$(CC) $(CFLAGS) -o $@ $(COMPTIME_C_FILES)

pregen.h: comptime
	./$< > $@

clean:
	rm -f pregen.h comptime smng

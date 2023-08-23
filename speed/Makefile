CC=cc
CFLAGS=-std=c99 -pedantic -Wall -Wextra -O2

RUSTC=cargo build
RUSTFLAGS=--release

all: target/c target/rs

target/c: states.c
	$(CC) $(CFLAGS) -o $@ $^

target/rs: rust/src/main.rs
	$(RUSTC) $(RUSTFLAGS) --manifest-path rust/Cargo.toml
	mv rust/target/release/states $@

clean:
	rm -f target/*

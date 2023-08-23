CC=cc
C_COPTS=-std=c99 -pedantic -Wall -Wextra

ZIGC=zig build-exe
ZIG_OPTS= 

GOC=go build
GO_OPTS=

all: target/c target/c2 target/go target/zig

target/c: cgol.c
	$(CC) $(C_COPTS) -g -o $@ $<

target/c2: c2/cgol.c2
	c2c -d c2/
	mv c2/output/cgol/cgol $@

target/zig: cgol.zig
	zig fmt $<
	$(ZIGC) $(ZIG_OPTS) -o $@ $<

target/go: go/cgol.go
	$(GOC) $(GO_OPTS) -o $@ $<

clean:
	rm -f target/*

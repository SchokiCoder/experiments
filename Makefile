CC = cc
C_COPTS = -std=c99 -pedantic
C_SRC = c/cgol.c

ZIGC = zig build-exe
ZIG_OPTS = 
ZIG_SRC = zig/cgol.zig

GOC = go build
GO_OPTS =
GO_SRC = go/cgol.go

cgol: c go zig

debug: c_debug go_debug zig_debug

c: clean
	$(CC) ${C_COPTS} -Os -o bin/$@ ${C_SRC}

c_debug: clean
	$(CC) ${C_COPTS} -g -o bin/c ${C_SRC} -Wall -Wextra

zig:
	zig fmt ${ZIG_SRC}
	$(ZIGC) ${ZIG_OPTS} ${ZIG_SRC} -O3
	mv a.out bin/$@

zig_debug:
	zig fmt ${ZIG_SRC}
	$(ZIGC) ${ZIG_OPTS} ${ZIG_SRC}
	mv a.out bin/$@

go:
	$(GOC) ${GO_OPTS} -o bin/$@ ${GO_SRC}

go_debug:
	$(GOC) ${GO_OPTS} -o bin/go ${GO_SRC}

clean:
	rm -f bin/*

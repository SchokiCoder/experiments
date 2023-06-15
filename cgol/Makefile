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
	$(CC) ${C_COPTS} -Os -o target/$@ ${C_SRC}

c_debug: clean
	$(CC) ${C_COPTS} -g -o target/c ${C_SRC} -Wall -Wextra

zig: clean
	zig fmt ${ZIG_SRC}
	$(ZIGC) ${ZIG_OPTS} ${ZIG_SRC} -O3
	mv a.out target/$@

zig_debug: clean
	zig fmt ${ZIG_SRC}
	$(ZIGC) ${ZIG_OPTS} ${ZIG_SRC}
	mv a.out target/$@

go: clean
	$(GOC) ${GO_OPTS} -o target/$@ ${GO_SRC}

go_debug: clean
	$(GOC) ${GO_OPTS} -o target/go ${GO_SRC}

clean:
	rm -f target/*

C_CC = cc
C_COPTS = -std=c99 -pedantic
C_SRC = c/cgol.c

GO_CC = go build
GO_OPTS =
GO_SRC = go/cgol.go

cgol: c_cgol go_cgol

debug: c_debug go_debug

c_cgol: clean
	$(C_CC) ${C_COPTS} -Os -o bin/$@ ${C_SRC}

c_debug: clean
	$(C_CC) ${C_COPTS} -g -o bin/c_cgol ${C_SRC} -Wall -Wextra

go_cgol:
	$(GO_CC) ${GO_OPTS} -o bin/$@ ${GO_SRC}

go_debug:
	$(GO_CC) ${GO_OPTS} -o bin/go_cgol ${GO_SRC}

clean:
	rm -f bin/*


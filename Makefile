# Makefile...

CC=cc
CFLAGS=-std=c99 -Wall
LFLAGS=-ledit -lm
LIBS=mpc.c
SOURCES=hello_world prompt doge doge_grammar polish_notation parsing s_expressions q_expressions read_file help

all: clean $(SOURCES) mlisp

%: %.c
	$(CC) $(CFLAGS) $^ $(LIBS) $(LFLAGS) -o bin/$@
	
mlisp:
	$(CC) $(CFLAGS) q_expressions.c $(LIBS) $(LFLAGS) -o mlisp

clean:
	rm -rf bin
	mkdir bin
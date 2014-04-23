# Makefile...

CC=cc
CFLAGS=-std=c99 -Wall
LFLAGS=-ledit -lm
LIBS=mpc.c

.PHONY: mlisp
all: clean mlisp

mlisp:
	$(CC) $(CFLAGS) mlisp.c $(LIBS) $(LFLAGS) -o mlisp

clean:
	rm -rf bin
	mkdir bin
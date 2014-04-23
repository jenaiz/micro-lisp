# Makefile...

CC=cc
CFLAGS=-std=c99 -Wall
LFLAGS=-ledit -lm
LIBS=mpc.c
SOURCES=hello_world prompt doge doge_grammar polish_notation parsing s_expressions q_expressions functions conditionals lispy

all: clean $(SOURCES)

%: %.c
	$(CC) $(CFLAGS) $^ $(LIBS) $(LFLAGS) -o ../bin/$@
	
clean:
	rm -rf ../bin
	mkdir ../bin
# Makefile...

CC=cc
CFLAGS=-std=c99 -Wall
LFLAGS=-ledit -lm
LIBS=mpc.c
SOURCES=hello_world prompt doge doge_grammar polish_notation parsing s_expressions q_expressions read_file help

all: clean hello_world prompt doge doge_grammar polish_notation parsing s_expressions q_expressions read_file help

hello_world:
	$(CC) $(CFLAGS) hello_world.c $(LIBS) $(LFLAGS) -o bin/hello_world
	
prompt:
	$(CC) $(CFLAGS) prompt.c $(LIBS) -ledit $(LFLAGS) -o bin/prompt

doge:
	$(CC) $(CFLAGS) doge.c $(LIBS) -ledit $(LFLAGS) -o bin/doge

doge_grammar:
	$(CC) $(CFLAGS) doge_grammar.c $(LIBS) $(LFLAGS) -o bin/doge_grammar

polish_notation:	
	$(CC) $(CFLAGS) polish_notation.c $(LIBS) $(LFLAGS) -o bin/polish_notation

parsing:
	$(CC) $(CFLAGS) parsing.c $(LIBS) $(LFLAGS) -o bin/parsing

s_expressions:
	$(CC) $(CFLAGS) s_expressions.c $(LIBS) $(LFLAGS) -o bin/s_expressions

q_expressions:
	$(CC) $(CFLAGS) q_expressions.c $(LIBS) $(LFLAGS) -o bin/q_expressions

read_file:		
	$(CC) $(CFLAGS) read_file.c $(LIBS) $(LFLAGS) -o bin/read_file

help:	
	$(CC) $(CFLAGS) help.c $(LIBS) $(LFLAGS) -o bin/help

mlisp:
	$(CC) $(CFLAGS) q_expressions.c $(LIBS) $(LFLAGS) -o mlisp

clean:
	rm -rf bin
	mkdir bin
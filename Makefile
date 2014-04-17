# Makefile...

CC=cc
CFLAGS=-std=c99 -Wall
LIBS=mpc.c


all: clean doge doge_grammar polish_notation parsing s_expressions q_expressions read_file help
	
prompt:
	$(CC) $(CFLAGS) prompt.c $(LIBS) -ledit -lm -o bin/doge

doge:
	$(CC) $(CFLAGS) doge.c $(LIBS) -ledit -lm -o bin/doge

doge_grammar:
	$(CC) $(CFLAGS) doge_grammar.c $(LIBS) -ledit -lm -o bin/doge_grammar

polish_notation:	
	$(CC) $(CFLAGS) polish_notation.c $(LIBS) -ledit -lm -o bin/polish_notation

parsing:
	$(CC) $(CFLAGS) parsing.c $(LIBS) -ledit -lm -o bin/parsing

s_expressions:
	$(CC) $(CFLAGS) s_expressions.c $(LIBS) -ledit -lm -o bin/s_expressions

q_expressions:
	$(CC) $(CFLAGS) q_expressions.c $(LIBS) -ledit -lm -o bin/q_expressions

read_file:		
	$(CC) $(CFLAGS) read_file.c $(LIBS) -ledit -lm -o bin/read_file

help:	
	$(CC) $(CFLAGS) help.c $(LIBS) -ledit -lm -o bin/help

mlisp:
	$(CC) $(CFLAGS) q_expressions.c $(LIBS) -ledit -lm -o mlisp


clean:
	rm -rf bin/
	mkdir bin
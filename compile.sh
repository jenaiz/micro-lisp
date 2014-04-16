rm -rf bin/
mkdir bin
#cc -std=c99 -Wall read_file.c mpc.c -ledit -lm -o bin/read_file
#cc -std=c99 -Wall help.c mpc.c -ledit -lm -o bin/help
#cc -std=c99 -Wall prompt.c -ledit -o bin/prompt
#cc -std=c99 -Wall doge.c mpc.c -ledit -lm -o bin/doge
#cc -std=c99 -Wall doge_grammar.c mpc.c -ledit -lm -o bin/doge_grammar
#cc -std=c99 -Wall polish_notation.c mpc.c -ledit -lm -o bin/polish_notation
#cc -std=c99 -Wall parsing.c mpc.c -ledit -lm -o bin/parsing
#cc -std=c99 -Wall s_expressions.c mpc.c -ledit -lm -o bin/s_expressions
cc -std=c99 -Wall q_expressions.c mpc.c -ledit -lm -o bin/mlisp

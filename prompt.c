#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32

#include <string.h>

static char buffer[2048];

/* Fake readline function */
char* readline(char* prompt) {
  fputs(prompt, stdout);
  fgets(buffer, 2048, stdin);
  char* cpy = malloc(strlen(buffer)+1);
  strcpy(cpy, buffer);

  cpy[strlen(ctr)-1] = '\0';
  
  return cpy;
}

/* Fake add_history function */

void add_history(char* unused) {}

#else

#include <editline/readline.h>

#endif


int main(int argc, char** argv) {
  puts("µLisp v0.0.1");
  puts("Ctrl + c to exit.");
	
  while(1) {
		char* input = readline("µLisp >> ");

    add_history(input);
		
		printf("You are now %s\n", input);

    free(input);
	}

	return 0;
}
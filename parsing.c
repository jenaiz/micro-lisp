#include <stdio.h>
#include <stdlib.h>
#include "mpc.h"


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

/* Use operator string to see which operation to perform */
long eval_op(long x, char* op, long y) {
  if (strcmp(op, "+") == 0) { return x + y; }
  if (strcmp(op, "-") == 0) { return x - y; }
  if (strcmp(op, "*") == 0) { return x * y; }
  if (strcmp(op, "/") == 0) { return x / y; }
  return 0;
}

long eval(mpc_ast_t* t) {
  
  /* If tagged as number return it directly, otherwise expression. */ 
  if (strstr(t->tag, "number")) { return atoi(t->contents); }
  
  /* The operator is always second child. */
  char* op = t->children[1]->contents;
  
  /* We store the third child in `x` */
  long x = eval(t->children[2]);
  
  /* Iterate the remaining children, combining using our operator */
  int i = 3;
  while (strstr(t->children[i]->tag, "expr")) {
    x = eval_op(x, op, eval(t->children[i]));
    i++;
  }
  
  return x;
}

int main(int argc, char** argv) {
  
  /* Create Some Parsers */
  mpc_parser_t* Number   = mpc_new("number");
  mpc_parser_t* Operator = mpc_new("operator");
  mpc_parser_t* Expr     = mpc_new("expr");
  mpc_parser_t* Microlisp    = mpc_new("microlisp");

  /* Define them with the following Language */
  mpca_lang(MPC_LANG_DEFAULT,
    "                                                     \
      number   : /-?[0-9]+/ ;                             \
      operator : '+' | '-' | '*' | '/' ;                  \
      expr     : <number> | '(' <operator> <expr>+ ')' ;  \
      microlisp : /^/ <operator> <expr>+ /$/ ;            \
    ",
    Number, Operator, Expr, Microlisp);

  puts("µLisp v0.0.1");
  puts("[Apple LLVM version 5.1 (clang-503.0.38) (based on LLVM 3.4svn)]");
  puts("Ctrl + c to exit.");
  
  while(1) {
    char* input = readline("µL >> ");

    add_history(input);
    
    // printf("You are now %s\n", input);

    mpc_result_t r;
    if (mpc_parse("<stdin>", input, Microlisp, &r)) {
      //mpc_ast_print(r.output); // print an Abstract Syntax Tree
      
      long result = eval(r.output);
      printf("%li\n", result);
      
      /*mpc_ast_t* a = r.output;
      printf("Tag: %s\n", a->tag);
      printf("Contents: %s\n", a->contents);
      printf("Number of children: %i\n", a->children_num);

      mpc_ast_t* child_1 = a->children[0];
      printf("First child Tag: %s\n", child_1->tag);
      printf("First child Contents: %s\n", child_1->contents);
      printf("First child Number of children: %i\n", child_1->children_num);
      */
      mpc_ast_delete(r.output);
    } else {
      mpc_err_print(r.error);
      mpc_err_delete(r.error);
    }

    free(input);
  }

  /* Undefine and Delete our Parsers */
  mpc_cleanup(4, Number, Operator, Expr, Microlisp);
  
  return 0;
}




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

typedef struct {
  int type;
  long num;
  int err;  
} lval;

/* enumeration with the possible lval types */
enum { LVAL_NUM, LVAL_ERR};

/* posible error types */
enum { LERR_DIV_ZERO, LERR_BAD_OP, LERR_BAD_NUM};


void init();
lval lval_num(long x);
lval lval_err(int x);
void lval_print(lval v);
lval eval_op(lval x, char* op, lval y);
lval eval(mpc_ast_t* t);
void lval_println(lval v);


int main(int argc, char** argv) {
  
  /* Create Some Parsers */
  mpc_parser_t* Number   = mpc_new("number");
  mpc_parser_t* Operator = mpc_new("operator");
  mpc_parser_t* Expr     = mpc_new("expr");
  mpc_parser_t* Microlisp    = mpc_new("microlisp");

  /* Define them with the following Language */
  mpca_lang(MPCA_LANG_DEFAULT,
    "                                                     \
      number   : /-?[0-9]+/ ;                             \
      operator : '+' | '-' | '*' | '/' ;                  \
      expr     : <number> | '(' <operator> <expr>+ ')' ;  \
      microlisp : /^/ <operator> <expr>+ /$/ ;            \
    ",
    Number, Operator, Expr, Microlisp);
  init();
  
  while(1) {
    char* input = readline("µL >> ");

    add_history(input);
    
    mpc_result_t r;
    if (mpc_parse("<stdin>", input, Microlisp, &r)) {      
      lval result = eval(r.output);
      lval_println(result);
      
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

/* functions... */
void init() {
  puts("µLisp v0.0.2");
  puts("Ctrl + c to exit.");
}

lval lval_num(long x) {
  lval v;
  v.type = LVAL_NUM;
  v.num = x;
  return v;
}

lval lval_err(int x) {
  lval v;
  v.type = LVAL_ERR;
  v.num = x;
  return v;
}

void lval_print(lval v) {
  switch (v.type) {
    case LVAL_NUM: printf("%li", v.num); break;

    case LVAL_ERR: 
      if (v.err == LERR_DIV_ZERO) { printf("Error: Division by Zero!"); }
      if (v.err == LERR_BAD_OP)   { printf("Error: Invalid Operator!"); }
      if (v.err == LERR_BAD_NUM)  { printf("Error: Invalid Number!"); }
    break;
  }
}

/* Use operator string to see which operation to perform */
lval eval_op(lval x, char* op, lval y) {

  if (x.type == LVAL_ERR) { return x; }
  if (y.type == LVAL_ERR) { return y; }

  if (strcmp(op, "+") == 0) { return lval_num(x.num + y.num); }
  if (strcmp(op, "-") == 0) { return lval_num(x.num - y.num); }
  if (strcmp(op, "*") == 0) { return lval_num(x.num * y.num); }
  if (strcmp(op, "/") == 0) { 
    return y.num == 0? lval_err(LERR_DIV_ZERO) : lval_num(x.num / y.num); 
  }
  
  return lval_err(LERR_BAD_OP);
}

lval eval(mpc_ast_t* t) {
  
  /* If tagged as number return it directly, otherwise expression. */ 
  if (strstr(t->tag, "number")) { 
    errno = 0;
    long x = strtol(t->contents, NULL, 10);

    return errno != ERANGE ? lval_num(x) : lval_err(LERR_BAD_NUM); 
  }
  
  /* The operator is always second child. */
  char* op = t->children[1]->contents;
  
  /* We store the third child in `x` */
  lval x = eval(t->children[2]);
  
  /* Iterate the remaining children, combining using our operator */
  int i = 3;
  while (strstr(t->children[i]->tag, "expr")) {
    x = eval_op(x, op, eval(t->children[i]));
    i++;
  }
  
  return x;
}

void lval_println(lval v) { lval_print(v); putchar('\n'); }




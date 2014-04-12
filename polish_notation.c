/*
 * polish_notation.c
 *
 * "a program is an operator followed by one or more expressions,"
 * "an expression is either a number, or, in parenthesis, an operator followed by one or more expressions"
 *
*/
#include <stdio.h>
#include "mpc.h"


int main(int argc, char** argv) {

  mpc_parser_t* Adjective = mpc_new("adjective");
  mpc_parser_t* Noun		= mpc_new("noun");
  mpc_parser_t* Phrase 	= mpc_new("phrase");
  mpc_parser_t* Doge 		= mpc_new("doge");

  mpca_lang(MPC_LANG_DEFAULT,
  	" \
  	  number       : /-?[0-9]+/; \
  	  operator     : + | - | / | * ; \
      expression   :  | <expression> | (<expression>) | <number> <operator> <number> ;	\
  	  expressions  : <expression> <expression>; \
  	  program : <expressions>*; \
  	",
  	Adjective, Noun, Phrase, Doge);

  /* Do some parsing here ... */

  mpc_cleanup(4, Adjective, Noun, Phrase, Doge);

  return 0;

}
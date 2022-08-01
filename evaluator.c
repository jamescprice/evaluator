/*evaluator.c
  This evaluator for arithmetic expressions is part of the term project for the
  MIT SIPB Crash Course in C for IAP 1999.  Copyright (c) 1998 Matthew
  Belmonte.*/

#include <stdio.h>
#include "scanner.h"	/*needed for input*/
#include "parser.h"

static int eval(Tree * expr)
//Tree *expr;
  {
  int divisor;
/*'expr' points to a parse tree representing an arithmetic expression*/
  switch(TreeOper(expr))
    {
    case NumberToken: return(TreeValue(expr));
    case PlusToken: return(eval(TreeLeft(expr)) + eval(TreeRight(expr)));
    case MinusToken: return(eval(TreeLeft(expr)) - eval(TreeRight(expr)));
    case TimesToken: return(eval(TreeLeft(expr)) * eval(TreeRight(expr)));
    case DivideToken:
      divisor = eval(TreeRight(expr));
      if(divisor == 0)				/*check for division by 0*/
	{
	printf("error: one ought not to divide by nought\n");
	exit(1);
	}
      return(eval(TreeLeft(expr)) / divisor);
    default:  print_tree(expr);}
  }

int main()
  { 
  Tree *p;
printf("ENTER ARITHMETIC EXPRESSION:\n");
 p = parse_expr();
  printf("\nPARSE TREE STRUCTURE:\n");
 print_tree(p);

  printf("\nEXPRESSION EVALUATES TO:\n");

//  printf("\n%d\n", eval(parse_expr()));
  printf("%d\n", eval(p));

  return 0;
  }

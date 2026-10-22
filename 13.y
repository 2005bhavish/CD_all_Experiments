
%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}

%token ID

%%

E : T
  ;

T : T '*' F
  | F
  ;

F : '(' E ')'
  | ID
  ;

%%

void yyerror(const char *s)
{
    printf("Invalid Expression\n");
}

int main()
{
    printf("Enter an expression: ");

    if (yyparse() == 0)
        printf("Valid Expression\n");

    return 0;
}

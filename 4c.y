
%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(const char *s);
%}

%token NUMBER

%left '+' '-'
%left '*' '/'
%left UMINUS

%%

input:
    expression '\n' { printf("Result = %d\n", $1); }
    ;

expression:
    NUMBER                  { $$ = $1; }
    | expression '+' expression { $$ = $1 + $3; }
    | expression '-' expression { $$ = $1 - $3; }
    | expression '*' expression { $$ = $1 * $3; }
    | expression '/' expression
      {
          if ($3 == 0)
          {
              printf("Error: Division by zero\n");
              YYABORT;
          }
          $$ = $1 / $3;
      }
    | '(' expression ')'    { $$ = $2; }
    | '-' expression %prec UMINUS { $$ = -$2; }
    ;

%%

void yyerror(const char *s)
{
    printf("Invalid expression\n");
}

int main()
{
    printf("Enter arithmetic expression: ");
    yyparse();
    return 0;
}


%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
int yyerror(char *s);
%}

%token NUMBER

%left '+' '-'
%left '*' '/'

%%

S : E '\n'
    {
        printf("Result = %d\n", $1);
    }
    ;

E : E '+' E  { $$ = $1 + $3; }
  | E '-' E  { $$ = $1 - $3; }
  | E '*' E  { $$ = $1 * $3; }
  | E '/' E
    {
        if ($3 == 0)
        {
            printf("Error: Division by zero\n");
            YYABORT;
        }
        $$ = $1 / $3;
    }
  | '(' E ')' { $$ = $2; }
  | NUMBER    { $$ = $1; }
  ;

%%

int main()
{
    printf("Enter expression: ");
    yyparse();
    return 0;
}

int yyerror(char *s)
{
    printf("Invalid expression\n");
    return 0;
}

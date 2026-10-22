
%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
int valid = 1;
void yyerror(const char *s);
%}

%token NUMBER

%left '+' '-'
%left '*' '/'

%%

input:
    expression '\n'
    {
        if (valid)
            printf("Valid arithmetic expression\n");
    }
    ;

expression:
    NUMBER
    | expression '+' expression
    | expression '-' expression
    | expression '*' expression
    | expression '/' expression
    ;

%%

void yyerror(const char *s)
{
    printf("Invalid arithmetic expression\n");
    valid = 0;
}

int main()
{
    printf("Enter an arithmetic expression: ");
    yyparse();
    return 0;
}

Enter an arithmetic expression: 2+7*5
Valid arithmetic expression

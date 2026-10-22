
%{
#include <stdio.h>
%}

%%

[a-zA-Z][a-zA-Z0-9]* {
    printf("Valid variable\n");
    return 0;
}

.* {
    printf("Invalid variable\n");
    return 0;
}

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter a variable: ");
    yylex();
    return 0;
}

// Enter a variable: aB75D6q2
// Valid variable
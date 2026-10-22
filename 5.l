
%{
#include "exp5.tab.h"
#include <stdlib.h>
#include <string.h>
%}

%%

[0-9]+ {
    yylval.str = strdup(yytext);
    return NUMBER;
}

[ \t]   ;
\n      return '\n';
.       return yytext[0];

%%

int yywrap()
{
    return 1;
}



// Enter expression: 2+3*4

// Abstract Syntax Tree:
//           4
//      *
//           3
// +
//      2
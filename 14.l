
%{
#include "Exp14.tab.h"
#include <stdlib.h>
%}

%%

[0-9]+  {
            yylval = atoi(yytext);
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

// Enter expression: 3+5*2
// Result = 13
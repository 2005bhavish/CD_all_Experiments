
%{
#include "y.tab.h"
%}

DIGIT [0-9]

%%

{DIGIT}+    { return NUMBER; }
[+\-*/]     { return yytext[0]; }
[ \t]       ;
\n          { return '\n'; }
.           { return yytext[0]; }

%%

int yywrap()
{
    return 1;
}

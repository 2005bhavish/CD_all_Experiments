
%{
#include "parser13.tab.h"
%}

%%

[a-zA-Z][a-zA-Z0-9]*  { return ID; }
"*"                   { return '*'; }
"("                   { return '('; }
")"                   { return ')'; }
[ \t\n]+              ;
.                     { return yytext[0]; }

%%

int yywrap()
{
    return 1;
}


// Enter an expression: id*id*id
// Valid Expression
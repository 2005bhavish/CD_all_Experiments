
%{
#include <stdio.h>

int word_count = 0;
int line_count = 0;
%}

%%

\n              {
                    line_count++;
                    printf("After line %d: words=%d\n",
                           line_count, word_count);
                }

[ \t]+          ;

[^ \t\n]+       {
                    word_count++;
                }

%%

int main()
{
    printf("Enter text (Ctrl+Z to end input):\n");
    yylex();

    printf("\nFinal count -> lines: %d, words: %d\n",
           line_count, word_count);

    return 0;
}

int yywrap()
{
    return 1;
}

// Enter text (Ctrl+Z to end input):
// hello all lex program
// After line 1: words=4
// This is experiment eight
// After line 2: words=8

// Final count -> lines: 2, words: 8
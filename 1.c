
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void main()
{
    int i = 0, j = 0, x = 0, n;
    void *p, *add[15];
    char b[15], d[15], c;

    printf("Expression terminated by $: ");

    while ((c = getchar()) != '$')
    {
        b[i] = c;
        i++;
    }

    n = i - 1;

    printf("Given expression: ");
    i = 0;

    while (i <= n)
    {
        printf("%c", b[i]);
        i++;
    }

    printf("\nSymbol Table\n");
    printf("Symbol\tAddress\tType\n");

    while (j <= n)
    {
        c = b[j];

        if (isalpha(c))
        {
            p = malloc(c);
            add[x] = p;
            d[x] = c;

            printf("%c\t%p\tIdentifier\n", c, p);

            x++;
            j++;
        }
        else
        {
            c = b[j];

            if (c == '+' || c == '-' || c == '*' ||
                c == '=' || c == '/')
            {
                p = malloc(sizeof(char));
                add[x] = p;
                d[x] = c;

                printf("%c\t%p\tOperator\n", c, p);

                x++;
                j++;
            }
            else
            {
                j++;
            }
        }
    }
}

// Expression terminated by $: a+b$
// Given expression: a+b
// Symbol Table
// Symbol  Address Type
// a       00D31E50        Identifier
// +       00D31DC8        Operator
// b       00D318A0        Identifier
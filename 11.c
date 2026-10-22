
#include <stdio.h>
#include <ctype.h>

enum { A, LP, RP, C, END, INV } t;
const char *p;

void next()
{
    while (isspace((unsigned char)*p))
        p++;

    switch (*p)
    {
        case 'a': t = A; break;
        case '(': t = LP; break;
        case ')': t = RP; break;
        case ',': t = C; break;
        case '\0': t = END; return;
        default: t = INV;
    }

    p++;
}

int S();
int L();

int S()
{
    if (t == A)
    {
        next();
        return 1;
    }

    if (t == LP)
    {
        next();

        if (L() && t == RP)
        {
            next();
            return 1;
        }
    }

    return 0;
}

int L()
{
    if (!S())
        return 0;

    while (t == C)
    {
        next();

        if (!S())
            return 0;
    }

    return 1;
}

int main()
{
    char s[256];

    printf("Enter expression: ");
    fgets(s, sizeof(s), stdin);

    p = s;
    next();

    if (S() && t == END)
        printf("Parsing succeeded: valid expression\n");
    else
        printf("Parsing failed: invalid expression\n");

    return 0;
}

// Enter expression: (a)
// Parsing succeeded: valid expression
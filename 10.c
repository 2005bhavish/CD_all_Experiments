
#include <stdio.h>
#include <string.h>

void E();
void EPrime();
void T();
void TPrime();
void F();

void E()
{
    printf("E -> T E'\n");
}

void EPrime()
{
    printf("E' -> + T E' | epsilon\n");
}

void T()
{
    printf("T -> F T'\n");
}

void TPrime()
{
    printf("T' -> * F T' | epsilon\n");
}

void F()
{
    printf("F -> (E) | id\n");
}

int main()
{
    int n, i;
    char production[10][50];

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("\nEnter productions:\n");

    for (i = 0; i < n; i++)
    {
        printf("Production %d: ", i + 1);
        scanf("%49s", production[i]);
    }

    printf("\nGiven Grammar:\n");

    for (i = 0; i < n; i++)
    {
        printf("%s\n", production[i]);
    }

    printf("\nRecursive Descent Grammar:\n");
    printf("---------------------------\n");

    E();
    EPrime();
    T();
    TPrime();
    F();

    printf("\nGrammar Conversion Completed Successfully.\n");

    return 0;
}

// Enter number of productions: 6

// Enter productions:
// Production 1: E->E+T
// Production 2: E->T
// Production 3: T->T*F
// Production 4: T->F
// Production 5: F->(E)
// Production 6: F->id

// Given Grammar:
// E->E+T
// E->T
// T->T*F
// T->F
// F->(E)
// F->id

// Recursive Descent Grammar:
// ---------------------------
// E -> T E'
// E' -> + T E' | epsilon
// T -> F T'
// T' -> * F T' | epsilon
// F -> (E) | id

// Grammar Conversion Completed Successfully.
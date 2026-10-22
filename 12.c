
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char production[10][20];
char first[10][20];
int n;

int present(char str[], char ch)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ch)
            return 1;
    }

    return 0;
}

void addFirst(int index, char ch)
{
    int len;

    if (!present(first[index], ch))
    {
        len = strlen(first[index]);
        first[index][len] = ch;
        first[index][len + 1] = '\0';
    }
}

void findFirst(char symbol, int index)
{
    int i;
    char rhs;

    for (i = 0; i < n; i++)
    {
        if (production[i][0] == symbol)
        {
            rhs = production[i][3];

            if (!isupper((unsigned char)rhs))
            {
                if (rhs == 'i')
                    addFirst(index, 'i');
                else
                    addFirst(index, rhs);
            }
            else
            {
                if (rhs != symbol)
                    findFirst(rhs, index);
            }
        }
    }
}

int main()
{
    int i, j;

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions:\n");

    for (i = 0; i < n; i++)
        scanf("%19s", production[i]);

    for (i = 0; i < n; i++)
    {
        if (i == 0 || production[i][0] != production[i - 1][0])
            findFirst(production[i][0], i);
    }

    printf("\nFIRST Sets:\n");
    printf("-------------------------\n");

    for (i = 0; i < n; i++)
    {
        if (i > 0 && production[i][0] == production[i - 1][0])
            continue;

        printf("FIRST(%c) = { ", production[i][0]);

        for (j = 0; first[i][j] != '\0'; j++)
        {
            if (first[i][j] == 'i')
                printf("id ");
            else
                printf("%c ", first[i][j]);
        }

        printf("}\n");
    }

    return 0;
}

6
E->E+T
E->T
T->T*F
T->F
F->(E)
F->i

// FIRST Sets:
// -------------------------
// FIRST(E) = { ( id }
// FIRST(T) = { ( id }
// FIRST(F) = { ( id }
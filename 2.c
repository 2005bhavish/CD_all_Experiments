
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char str[100];
    int i = 0;

    printf("Enter Expression: ");
    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0')
    {
        if (isalpha(str[i]) || str[i] == '_')
        {
            printf("Identifier: ");

            while (isalnum(str[i]) || str[i] == '_')
            {
                putchar(str[i]);
                i++;
            }

            printf("\n");
        }
        else if (isdigit(str[i]))
        {
            printf("Constant: ");

            while (isdigit(str[i]))
            {
                putchar(str[i]);
                i++;
            }

            printf("\n");
        }
        else if (strchr("+-*/=<>!", str[i]) != NULL)
        {
            printf("Operator: %c\n", str[i]);
            i++;
        }
        else if (strchr("(){}[];,", str[i]) != NULL)
        {
            printf("Delimiter: %c\n", str[i]);
            i++;
        }
        else
        {
            i++;
        }
    }

    return 0;
}

// Enter Expression: a+b
// Identifier: a
// Operator: +
// Identifier: b
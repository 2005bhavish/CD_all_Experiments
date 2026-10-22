
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *kw[] = {
    "int", "float", "if", "else",
    "while", "return", "char", "void"
};

int isKeyword(char *s)
{
    int i;

    for (i = 0; i < 8; i++)
    {
        if (strcmp(s, kw[i]) == 0)
            return 1;
    }

    return 0;
}

int main()
{
    FILE *f;
    char file[100];
    int ch, n, i;
    char buf[100];

    printf("Enter file name: ");
    scanf("%99s", file);

    f = fopen(file, "r");

    if (f == NULL)
    {
        printf("File not found!\n");
        return 0;
    }

    while ((ch = fgetc(f)) != EOF)
    {
        if (isspace(ch))
            continue;

        if (ch == '/')
        {
            n = fgetc(f);

            if (n == '/')
            {
                while ((ch = fgetc(f)) != '\n' && ch != EOF)
                    ;
                continue;
            }

            if (n == '*')
            {
                while ((ch = fgetc(f)) != EOF)
                {
                    if (ch == '*')
                    {
                        n = fgetc(f);
                        if (n == '/')
                            break;
                        if (n != EOF)
                            ungetc(n, f);
                    }
                }
                continue;
            }

            if (n != EOF)
                ungetc(n, f);
        }

        if (isalpha(ch) || ch == '_')
        {
            i = 0;

            do
            {
                if (i < 99)
                    buf[i++] = ch;
                ch = fgetc(f);
            }
            while (isalnum(ch) || ch == '_');

            buf[i] = '\0';

            if (ch != EOF)
                ungetc(ch, f);

            if (isKeyword(buf))
                printf("<KEYWORD, %s>\n", buf);
            else
                printf("<IDENTIFIER, %s>\n", buf);
        }
        else if (isdigit(ch))
        {
            i = 0;

            do
            {
                if (i < 99)
                    buf[i++] = ch;
                ch = fgetc(f);
            }
            while (isdigit(ch));

            buf[i] = '\0';

            if (ch != EOF)
                ungetc(ch, f);

            printf("<NUMBER, %s>\n", buf);
        }
        else if (strchr("+-*/%=<>!", ch))
        {
            printf("<OPERATOR, %c>\n", ch);
        }
        else if (strchr("(){}[],;", ch))
        {
            printf("<SYMBOL, %c>\n", ch);
        }
    }

    fclose(f);
    return 0;
}

// Enter file name: input.txt
// <KEYWORD, int>
// <IDENTIFIER, main>
// <SYMBOL, (>
// <SYMBOL, )>
// <SYMBOL, {>
// <KEYWORD, int>
// <IDENTIFIER, a>
// <OPERATOR, =>
// <NUMBER, 5>
// <SYMBOL, ;>
// <KEYWORD, if>
// <SYMBOL, (>
// <IDENTIFIER, a>
// <OPERATOR, >>
// <NUMBER, 2>
// <SYMBOL, )>
// <IDENTIFIER, a>
// <OPERATOR, =>
// <IDENTIFIER, a>
// <OPERATOR, +>
// <NUMBER, 1>
// <SYMBOL, ;>
// <KEYWORD, return>
// <NUMBER, 0>
// <SYMBOL, ;>
// <SYMBOL, }>
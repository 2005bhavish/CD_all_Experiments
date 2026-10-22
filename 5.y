
%{
#include <stdio.h>
#include <stdlib.h>

struct node {
    char *value;
    struct node *left, *right;
};

struct node* newnode(char *v, struct node *l, struct node *r)
{
    struct node *n = malloc(sizeof(struct node));
    n->value = v;
    n->left = l;
    n->right = r;
    return n;
}

void printTree(struct node *n, int space)
{
    if (n == NULL)
        return;

    printTree(n->right, space + 5);
    printf("%*s%s\n", space, "", n->value);
    printTree(n->left, space + 5);
}

int yylex();
int yyerror(char *s);
%}

%union {
    struct node *ptr;
    char *str;
}

%token <str> NUMBER
%type <ptr> E

%left '+' '-'
%left '*' '/'

%%

S : E '\n'
    {
        printf("\nAbstract Syntax Tree:\n");
        printTree($1, 0);
    }
    ;

E : E '+' E
    {
        $$ = newnode("+", $1, $3);
    }
  | E '-' E
    {
        $$ = newnode("-", $1, $3);
    }
  | E '*' E
    {
        $$ = newnode("*", $1, $3);
    }
  | E '/' E
    {
        $$ = newnode("/", $1, $3);
    }
  | '(' E ')'
    {
        $$ = $2;
    }
  | NUMBER
    {
        $$ = newnode($1, NULL, NULL);
    }
    ;

%%

int main()
{
    printf("Enter expression: ");
    yyparse();
    return 0;
}

int yyerror(char *s)
{
    printf("Invalid expression\n");
    return 0;
}

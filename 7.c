
#include <stdio.h>

#define STACK_SIZE 10

int stackMemory[STACK_SIZE];
int stackTop = -1;

void push(int value)
{
    if (stackTop >= STACK_SIZE - 1)
    {
        printf(">> Stack Overflow! Cannot push %d\n", value);
        return;
    }

    stackMemory[++stackTop] = value;
    printf(">> Pushed %d -> stack[%d]\n", value, stackTop);
}

void pop(void)
{
    if (stackTop < 0)
    {
        printf(">> Stack Underflow! Stack is empty\n");
        return;
    }

    int value = stackMemory[stackTop--];
    printf(">> Popped %d <- stack[%d]\n", value, stackTop + 1);
}

void display(void)
{
    if (stackTop < 0)
    {
        printf(">> Stack is empty\n");
        return;
    }

    printf(">> Stack (top -> bottom): ");

    for (int i = stackTop; i >= 0; i--)
        printf("%d ", stackMemory[i]);

    printf("\n");
}

int main(void)
{
    int choice, value;

    printf("STACK STORAGE ALLOCATION DEMO\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    while (1)
    {
        printf("\nEnter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf(">> Invalid input. Exiting.\n");
            break;
        }

        switch (choice)
        {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf(">> Exiting program.\n");
                return 0;

            default:
                printf(">> Invalid choice! Try again.\n");
        }
    }

    return 0;
}


STACK STORAGE ALLOCATION DEMO
1. Push
2. Pop
3. Display
4. Exit

// Enter your choice: 1
// Enter value to push: 10
// >> Pushed 10 -> stack[0]

// Enter your choice: 1
// Enter value to push: 20
// >> Pushed 20 -> stack[1]

// Enter your choice: 2
// >> Popped 20 <- stack[1]

// Enter your choice: 3
// >> Stack (top -> bottom): 10

// Enter your choice: 2
// >> Popped 10 <- stack[0]

// Enter your choice: 3
// >> Stack is empty

// Enter your choice: 4
// >> Exiting program.
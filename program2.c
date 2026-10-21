
#include <stdio.h>

int stack[100];
int top = -1;

void push()
{
    int value;

    if (top == 99)
    {
        printf("Stack Overflow");
    }
    else
    {
        printf("Enter element: ");
        scanf("%d", &value);

        top++;
        stack[top] = value;

        printf("Element pushed successfully");
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow");
    }
    else
    {
        printf("Popped element: %d", stack[top]);
        top--;
    }
}

void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("Stack elements: ");

        for (i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Program terminated");
                break;

            default:
                printf("Invalid choice");
        }

    } while (choice != 4);

    return 0;
}

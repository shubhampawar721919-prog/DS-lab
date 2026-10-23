
#include <stdio.h>

#define MAX 100

int q1[MAX], q2[MAX];
int f1 = 0, r1 = -1;
int f2 = 0, r2 = -1;

void push()
{
    int value, i;

    if (r1 == MAX - 1)
    {
        printf("Stack Overflow");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &value);

    q2[++r2] = value;

    while (f1 <= r1)
    {
        q2[++r2] = q1[f1++];
    }

    for (i = 0; i <= r2; i++)
    {
        q1[i] = q2[i];
    }

    f1 = 0;
    r1 = r2;

    f2 = 0;
    r2 = -1;

    printf("Element pushed successfully");
}

void pop()
{
    int i;

    if (r1 == -1)
    {
        printf("Stack Underflow");
        return;
    }

    printf("Popped element: %d", q1[f1]);

    for (i = 0; i < r1; i++)
    {
        q1[i] = q1[i + 1];
    }

    r1--;
    f1 = 0;
}

void display()
{
    int i;

    if (r1 == -1)
    {
        printf("Stack is empty");
        return;
    }

    printf("Stack elements (top to bottom): ");

    for (i = f1; i <= r1; i++)
    {
        printf("%d ", q1[i]);
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

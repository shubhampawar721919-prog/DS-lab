
#include <stdio.h>

#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

int isFull()
{
    return (front == 0 && rear == MAX - 1) ||
           (front == rear + 1);
}

int isEmpty()
{
    return front == -1;
}

void insertFront()
{
    int value;

    if (isFull())
    {
        printf("Deque Overflow");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &value);

    if (isEmpty())
        front = rear = 0;
    else if (front == 0)
        front = MAX - 1;
    else
        front--;

    deque[front] = value;
    printf("Element inserted at front");
}

void insertRear()
{
    int value;

    if (isFull())
    {
        printf("Deque Overflow");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &value);

    if (isEmpty())
        front = rear = 0;
    else if (rear == MAX - 1)
        rear = 0;
    else
        rear++;

    deque[rear] = value;
    printf("Element inserted at rear");
}

void deleteFront()
{
    if (isEmpty())
    {
        printf("Deque Underflow");
        return;
    }

    printf("Deleted element: %d", deque[front]);

    if (front == rear)
        front = rear = -1;
    else if (front == MAX - 1)
        front = 0;
    else
        front++;
}

void deleteRear()
{
    if (isEmpty())
    {
        printf("Deque Underflow");
        return;
    }

    printf("Deleted element: %d", deque[rear]);

    if (front == rear)
        front = rear = -1;
    else if (rear == 0)
        rear = MAX - 1;
    else
        rear--;
}

void display()
{
    int i;

    if (isEmpty())
    {
        printf("Deque is empty");
        return;
    }

    printf("Deque elements: ");

    i = front;

    while (1)
    {
        printf("%d ", deque[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n\n1. Insert Front");
        printf("\n2. Insert Rear");
        printf("\n3. Delete Front");
        printf("\n4. Delete Rear");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertFront();
                break;

            case 2:
                insertRear();
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Program terminated");
                break;

            default:
                printf("Invalid choice");
        }

    } while (choice != 6);

    return 0;
}


#include <stdio.h>

#define SIZE 10

int table[SIZE];

void initialize()
{
    int i;

    for (i = 0; i < SIZE; i++)
        table[i] = -1;
}

void linearProbing()
{
    int key, index, i;

    printf("Enter key: ");
    scanf("%d", &key);

    index = key % SIZE;

    for (i = 0; i < SIZE; i++)
    {
        int pos = (index + i) % SIZE;

        if (table[pos] == -1)
        {
            table[pos] = key;
            printf("Key inserted at index %d", pos);
            return;
        }
    }

    printf("Hash table is full");
}

void quadraticProbing()
{
    int key, index, i;

    printf("Enter key: ");
    scanf("%d", &key);

    index = key % SIZE;

    for (i = 0; i < SIZE; i++)
    {
        int pos = (index + i * i) % SIZE;

        if (table[pos] == -1)
        {
            table[pos] = key;
            printf("Key inserted at index %d", pos);
            return;
        }
    }

    printf("No available position found");
}

void display()
{
    int i;

    printf("\nIndex\tValue\n");

    for (i = 0; i < SIZE; i++)
    {
        if (table[i] == -1)
            printf("%d\tEmpty\n", i);
        else
            printf("%d\t%d\n", i, table[i]);
    }
}

int main()
{
    int choice;

    initialize();

    do
    {
        printf("\n1. Linear Probing");
        printf("\n2. Quadratic Probing");
        printf("\n3. Display");
        printf("\n4. Reset Table");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                linearProbing();
                break;

            case 2:
                quadraticProbing();
                break;

            case 3:
                display();
                break;

            case 4:
                initialize();
                printf("Table reset successfully");
                break;

            case 5:
                printf("Program terminated");
                break;

            default:
                printf("Invalid choice");
        }

    } while (choice != 5);

    return 0;
}

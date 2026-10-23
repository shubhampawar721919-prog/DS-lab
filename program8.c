
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert()
{
    struct node *newnode, *temp;
    int value;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }

    printf("Node inserted successfully");
}

void deleteNode()
{
    struct node *temp, *prev;
    int value;

    if (head == NULL)
    {
        printf("List is empty");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &value);

    temp = head;
    prev = NULL;

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value not found");
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("Node deleted successfully");
}

void display()
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("List is empty");
        return;
    }

    printf("Linked list: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");
}

int main()
{
    int choice;

    do
    {
        printf("\n\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                deleteNode();
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

    while (head != NULL)
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

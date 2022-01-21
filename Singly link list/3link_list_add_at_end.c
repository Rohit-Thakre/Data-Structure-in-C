#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node Node;

void add_at_end(Node *head, int data)
{
    Node *ptr, *temp;
    ptr = head;
    temp = malloc(sizeof(Node));
    temp->data = data;
    temp->link = NULL;

    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }

    ptr->link = temp;

    ptr = head;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }
    printf("\n\n\n");
}

int main()
{
    system("cls");
    system("color a");

    Node *head = malloc(sizeof(Node));
    head->data = 10;
    head->link = NULL;

    Node *current = malloc(sizeof(Node));
    current->data = 20;
    current->link = NULL;
    head->link = current;

    current = malloc(sizeof(Node));
    current->data = 30;
    current->link = NULL;
    head->link->link = current;

    int data = 5555;

    add_at_end(head, data);
    add_at_end(head, 50000);
    return 0;
}
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
}

void add_node(Node *head, int data)
{

    Node *new = malloc(sizeof(Node));
    new->data = data;
    new->link = NULL;
    Node *temp = head;
    while (temp != NULL && data > temp->link->data)
        temp = temp->link;

    new->link = temp->link;
    temp->link = new;
}

int main()
{
    system("cls");
    system("color a");

    Node *head = NULL;
    head = malloc(sizeof(Node));
    head->data = 10;
    head->link = NULL;

    add_at_end(head, 20);
    add_at_end(head, 30);
    add_at_end(head, 40);
    add_at_end(head, 50);

    add_node(head, 45);

    Node *ptr = head;

    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }

    return 0;
}
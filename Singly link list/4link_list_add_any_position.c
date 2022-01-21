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

void at_pos(Node *head, int data, int pos)
{
    // create node
    Node *ptr, *temp = malloc(sizeof(Node));
    temp->data = data;

    ptr = head;
    pos--;
    // int count = 0;
    while (pos != 1)
    {
        ptr = ptr->link;
        pos--;
    }

    temp->link = ptr->link;
    ptr->link = temp;
}

int main()
{
    system("cls");
    system("color a");

    Node *head = malloc(sizeof(Node));
    head->data = 10;
    head->link = NULL;

    int data = 20;

    add_at_end(head, data);
    add_at_end(head, 30);

    // ant any position
    at_pos(head, 50, 3);

    Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node Node;

// reverse fun
Node *link_reverse(Node *head)
{
    Node *temp = NULL, *temp2 = NULL;
    while (head != NULL)
    {
        temp2 = head->link;
        head->link = temp;
        temp = head;
        head = temp2;
    }
    head = temp;
    return head;
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

    head = link_reverse(head);

    Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
typedef struct node Node;

Node *create_node(Node *head, int data)
{
    Node *ptr = malloc(sizeof(Node));

    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = NULL;
}

Node *at_start(Node *head, int data)
{
    Node *temp;
    temp = create_node(head, data);

    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;
}

void traverse(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    system("cls");
    system("color a");

    Node *head;
    head = create_node(head, 10);
    head = at_start(head, 5);
    head = at_start(head, 2);
    traverse(head);

    return 0;
}
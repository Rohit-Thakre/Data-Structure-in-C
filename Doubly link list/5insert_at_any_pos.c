#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
typedef struct node Node;

Node *create_node(int data)
{
    Node *ptr = malloc(sizeof(Node));

    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = NULL;
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

Node *at_start(Node *head, int data)
{
    Node *temp;
    temp = create_node(data);

    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;
}

void at_end(Node *head, int data)
{
    Node *ptr = head, *temp;
    temp = create_node(data);

    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = temp;
    temp->prev = ptr;
}

void at_any_pos(Node *head, int data, int pos)
{
    Node *current, *temp, *next;
    temp = create_node(data);
    current = head;
    pos--;
    while (pos != 1)
    {
        current = current->next;
        pos--;
    }
    next = current->next;
    current->next = temp;
    temp->prev = current;
    temp->next = next;
    // free(next);
    // next = NULL;
}

int main()
{
    system("cls");
    system("color a");

    Node *head;
    head = create_node(10);
    head = at_start(head, 5);
    head = at_start(head, 2);
    at_end(head, 20);
    at_any_pos(head, 99, 5);
    traverse(head);

    return 0;
}
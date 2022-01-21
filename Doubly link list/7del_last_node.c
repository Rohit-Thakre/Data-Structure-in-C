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

void del_last(Node *head)
{
    Node *current, *last;
    current = head;

    while (current->next->next != NULL)
        current = current->next;

    last = current->next->next;
    current->next = NULL;
    free(last);
    current = NULL;
}
int main()
{
    system("cls");
    system("color a");

    Node *head;
    head = create_node(10);
    head = at_start(head, 5);
    head = at_start(head, 2);
    del_last(head);

    traverse(head);

    return 0;
}
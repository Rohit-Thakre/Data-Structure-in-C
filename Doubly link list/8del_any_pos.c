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

void del_pos(Node *head, int pos)
{
    Node *current = head, *next = NULL, *del = NULL;
    pos--;
    while (pos != 1)
    {
        current = current->next;
        pos--;
    }

    del = current->next;
    next = del->next;
    current->next = next;
    next->prev = current;
    free(del);
    del = NULL;
}

int main()
{
    system("cls");
    system("color a");

    Node *head;
    head = create_node(40);
    head = at_start(head, 30);
    head = at_start(head, 20);
    head = at_start(head, 10);

    del_pos(head, 3);

    traverse(head);

    return 0;
}
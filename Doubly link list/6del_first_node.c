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

// method 1
Node *del_first_m1(Node *head)
{
    Node *current = head;
    head = head->next;
    head->prev = NULL;

    free(current);
    current = NULL;
    return head;
}

// method 2
Node *del_first_m2(Node *head)
{
    head = head->next;
    free(head->prev);
    head->prev = NULL;
    return head;
}
int main()
{
    system("cls");
    system("color a");

    Node *head;
    head = create_node(10);
    head = at_start(head, 5);
    head = at_start(head, 2);

    head = del_first_m1(head);
    head = del_first_m2(head);

    traverse(head);

    return 0;
}
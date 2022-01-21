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
int main()
{
    system("cls");
    system("color a");

    Node *head;
    head = create_node(head, 10);
    printf("prev :%d\n", head->prev);
    printf("data:%d\n", head->data);
    printf("next :%d\n", head->next);

    return 0;
}
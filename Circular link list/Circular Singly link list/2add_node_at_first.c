#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node Node;

Node *circularSingly(int data)
{
    Node *temp = malloc(sizeof(Node));
    temp->data = data;
    temp->next = temp;
    return temp;
}

Node *add_first(Node *tail, int data)
{
    Node *temp = circularSingly(data);
    temp->next = tail->next;
    tail->next = temp;

    return tail;
}

void display(Node *tail)
{
    Node *ptr = tail->next;

    do
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != tail->next);
}
int main()
{
    system("cls");
    system("color a");

    int data = 35;
    Node *tail, *new_node;
    tail = circularSingly(10);

    tail = add_first(tail, 5);
    display(tail);
    return 0;
}
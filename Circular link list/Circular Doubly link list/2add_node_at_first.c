#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node Node;

Node *circularSingly(int data)
{
    Node *temp = malloc(sizeof(Node));
    temp->data = data;
    temp->next = temp;
    temp->prev = temp;
    return temp;
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

Node *add_at_first(Node *tail, int data)
{
    Node *temp = circularSingly(data);
    temp->next = tail->next;
    temp->prev = tail;
    tail->next = temp;
    return tail;
}
int main()
{
    system("cls");
    system("color a");

    int data = 89;
    Node *tail = NULL;
    tail = circularSingly(data);

    tail = add_at_first(tail, 10);

    display(tail);
    return 0;
}
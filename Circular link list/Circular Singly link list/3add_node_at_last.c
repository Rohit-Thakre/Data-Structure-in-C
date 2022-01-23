#include <stdio.h>

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

void display(Node *tail)
{
    Node *ptr = tail->next;

    do
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != tail->next);
}

Node *add_at_end(Node *tail, int data)
{
    Node *temp = circularSingly(data);
    temp->next = tail->next;
    tail->next = temp;
    tail = temp;
    return tail;
}

int main()
{
    system("cls");
    system("color a");

    Node *tail = circularSingly(10);
    printf("before\n");
    display(tail);

    tail = add_at_end(tail, 20);
    printf("\nafter\n");
    display(tail);

    return 0;
}
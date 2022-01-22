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
int main()
{
    system("cls");
    system("color a");

    int data = 35;
    Node *tail = NULL;
    tail = circularSingly(data);
    printf("adrs : %d\n", tail);
    printf("data : %d\n", tail->data);
    printf("next : %d\n", tail->next);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
typedef struct node Node;

int main()
{
    system("cls");
    system("color a");

    Node *head;
    head = malloc(sizeof(Node));

    head->prev = NULL;
    head->data = 10;
    head->next = NULL;

    printf("prev :%d\n", head->prev);
    printf("data:%d\n", head->data);
    printf("next :%d\n", head->next);

    return 0;
}
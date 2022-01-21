
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node Node;

Node *del_all(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->link;
        free(head);
        head = temp;
    }
}
int main()
{
    system("cls");
    system("color a");

    Node *head = malloc(sizeof(Node));
    head->data = 10;
    head->link = NULL;

    Node *current = malloc(sizeof(Node));
    current->data = 20;
    current->link = NULL;
    head->link = current;

    current = malloc(sizeof(Node));
    current->data = 30;
    current->link = NULL;
    head->link->link = current;

    head = del_all(head);

    if (head == NULL)
        printf("link list deleted successfully!");

    return 0;
}
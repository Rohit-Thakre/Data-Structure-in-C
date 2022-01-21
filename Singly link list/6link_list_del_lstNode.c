#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node Node;

void del_lstNode(Node *head)
{
    if (head == NULL)
        printf("the link list is already empty.\n");

    else if (head->link == NULL)
        printf("there is only one node in link list\n");

    else
    {
        Node *ptr = head;
        while (ptr->link->link != NULL)
            ptr = ptr->link;

        free(ptr->link->link);
        ptr->link = NULL;

        printf("\n\nbefore / after deletion of last node\n\n");
        ptr = head;
        while (ptr != NULL)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->link;
        }
    }
}

int main()
{
    system("cls");
    system("color a");

    Node *head = NULL;
    head = malloc(sizeof(Node));
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

    Node *ptr = head;

    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }

    del_lstNode(head);

    return 0;
}
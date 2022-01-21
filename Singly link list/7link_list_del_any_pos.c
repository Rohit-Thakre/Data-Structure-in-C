#include <stdlib.h>
#include <stdio.h>
// #include "abc.c"

struct node
{
    int data;
    struct node *link;
};

typedef struct node Node;

void del_any_pos(Node *head, int pos)
{
    if (head == NULL)
        printf("the link list is already empty!\n");
    else
    {
        Node *ptr = head;
        pos--;

        while (pos != 1)
        {
            ptr = ptr->link;
            pos--;
        }
        ptr->link = ptr->link->link;
        // the above code is equivalent to
        // privios->link = current->link;
        // free(current->link);
        // current = NULL;

        free(ptr->link->link);
        ptr->link->link = NULL;
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

    Node *ptr = head;

    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }

    del_any_pos(head, 2);

    printf("\n\nafter deletion of node\n");
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }

    return 0;
}
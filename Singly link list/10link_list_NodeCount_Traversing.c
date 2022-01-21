
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
typedef struct node Node;

void count_node(Node *hd)
{
    int count = 0;
    if (hd == NULL)
        // return count;
        printf("there are 0 nodes.\n");

    else
    {
        Node *cp_head;
        cp_head = hd;
        while (cp_head != NULL)
        {
            count++;
            cp_head = cp_head->link;
        }
        // return count;
        printf("there are %d nodes.\n", count);
    }
}

void traverse(Node *hd)
{
    if (hd == NULL)
        printf("the link list is empty\n");

    else
    {
        Node *cp_head;
        cp_head = hd;
        printf("the link list's data is : \n");
        while (cp_head != NULL)
        {
            printf("%d\n", cp_head->data);
            cp_head = cp_head->link;
        }
    }
}

int main()
{
    system("cls");
    system("color a");

    // Node *head = NULL;
    Node *head = malloc(sizeof(Node));
    head->data = 10;
    head->link = NULL;

    // printf("head->data : %d\n", head->data);
    // printf("head->link : %d\n\n", head->link);

    Node *current = malloc(sizeof(Node));
    current->data = 20;
    current->link = NULL;
    head->link = current;

    // printf("after adding new node.\nhead->link : %d\n", head->link);
    // printf("current->data : %d\n", current->data);
    // printf("current->link : %d\n\n", current->link);

    current = malloc(sizeof(Node));
    current->data = 30;
    current->link = NULL;
    head->link->link = current;
    // printf("after adding new node.\nhead->link : %d\n", head->link->link);
    // printf("current->data : %d\n", current->data);
    // printf("current->link : %d\n\n", current->link);

    count_node(head);
    traverse(head);

    return 0;
}
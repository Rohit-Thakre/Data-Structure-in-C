/* 
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// traversiong the linked list
print_list(struct node *n)
{
    while (n != NULL)
    {
        printf(" %d\n", n->data);
        n = n->next;
    }
}

void push(struct node **first, int data)
{
    struct node *new = NULL;
    new = (struct node *)malloc(sizeof(struct node));

    new->data = data;
    new->next = *first;
    (*first) = new;
}

int main()
{
    system("cls");
    struct node *first = NULL;
    struct node *second = NULL;
    struct node *third = NULL;

    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    first->data = 50;
    first->next = second;

    second->data = 60;
    second->next = third;

    third->data = 70;
    third->next = NULL;

    // printf("the address of first.data %u\n", &first->data);
    // printf("first.data %d\n", first->data);
    // printf("first.next %u\n\n", first->next);

    // printf("the address of second.data %u\n", &second->data);
    // printf("second.data %d\n", second->data);
    // printf("second.next %u\n\n", first->next);

    // printf("the address of third.data %u\n", &third->data);
    // printf("third.data %d\n", third->data);
    // printf("third.next %u\n", third->next);

    print_list(first);

    push(&first, 5);

    printf("new list\n");
    print_list(first);
} */

// method 2 :

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node Node;

int main()
{
    system("cls");
    system("color a");

    // Node *head = NULL;
    Node *head = malloc(sizeof(Node));
    head->data = 10;
    head->link = NULL;

    printf("head->data : %d\n", head->data);
    printf("head->link : %d\n\n", head->link);

    Node *current = malloc(sizeof(Node));
    current->data = 20;
    current->link = NULL;
    head->link = current;

    printf("after adding new node.\nhead->link : %d\n", head->link);
    printf("current->data : %d\n", current->data);
    printf("current->link : %d\n\n", current->link);

    current = malloc(sizeof(Node));
    current->data = 30;
    current->link = NULL;
    head->link->link = current;
    printf("after adding new node.\nhead->link : %d\n", head->link->link);
    printf("current->data : %d\n", current->data);
    printf("current->link : %d\n\n", current->link);

    return 0;
}
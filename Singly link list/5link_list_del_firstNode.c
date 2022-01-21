/* #include <stdio.h>
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

Node *del_firstNode(Node *head)
{
    if (head == NULL)
        printf("the link list is already empty!\n");
    else if (head->link == NULL)
        printf("there is only one node in the link list\n");

    else
    {
        Node *temp = head;
        head = head->link;
        free(temp);
        return head;
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

    Node *current = malloc(sizeof(Node));
    current->data = 20;
    current->link = NULL;
    head->link = current;

    current = malloc(sizeof(Node));
    current->data = 30;
    current->link = NULL;
    head->link->link = current;

    head = del_firstNode(head);

    Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *top = NULL;

typedef struct node Node;

int count = 0;
Node *temp = NULL;

Node *create(int data)
{
    temp = malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    count++;
    return temp;
}

Node *push(Node *head, int data)
{
    temp = create(data);
    temp->next = head;
    head = temp;
    return temp;
}

Node *pop(Node *head)
{
    temp = head;
    head = head->next;
    free(temp);
    temp = NULL;
    count--;
    return head;
}

void traverse(Node *head)
{
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    system("cls");
    system("color a");

    Node *head = create(10);
    head = push(head, 20);
    head = push(head, 30);
    head = push(head, 40);
    head = push(head, 50);

    traverse(head);

    head = pop(head);

    printf("\nAfter poping:\n");
    traverse(head);

    printf("the count of nodes is : %d", count);

    return 0;
}
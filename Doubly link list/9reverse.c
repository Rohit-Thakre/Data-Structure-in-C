#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
typedef struct node Node;

Node *create_node(int data)
{
    Node *ptr = malloc(sizeof(Node));

    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = NULL;
}

void traverse(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

Node *at_start(Node *head, int data)
{
    Node *temp;
    temp = create_node(data);

    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;
}

Node *reverse(Node *head)
{
    Node *ptr = NULL, *ptr2 = NULL;

    while (head->next != NULL)
    {
        ptr2 = head->next;
        head->prev = ptr2;
        head->next = ptr;
        ptr = head;
        head = ptr2;
    }
    head->prev = NULL;
    head->next = ptr;
    return head;
}
int main()
{
    system("cls");
    system("color a");

    Node *head;
    head = create_node(50);
    head = at_start(head, 40);
    head = at_start(head, 30);
    head = at_start(head, 20);
    head = at_start(head, 10);
    printf("before reverse.\n");
    traverse(head);

    printf("\n\nafter reverse.\n");
    head = reverse(head);
    traverse(head);

    return 0;
}
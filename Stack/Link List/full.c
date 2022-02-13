#include <stdio.h>
#include <stdlib.h>
#define max 5
int count = 0;
struct node
{
    int data;
    struct node *next;
};

typedef struct node node;
node *top = NULL;

node *create(int data)
{

    node *temp = malloc(sizeof(node));
    temp->next = NULL;
    temp->data = data;
    count++;
    return temp;
}

int isfull()
{
    if (count == max)
        return 1;
    else
        return 0;
}

int isnull()
{
    if (count < 0)
        return 1;
    else
        return 0;
}

/* ------------------------------------------------------------------------------------ */

node *push(node *top, int data)
{
    if (isfull())
    {
        printf("stack overflow.\n");
        // return;
        exit(1);
    }

    node *temp = create(data);
    top->next = temp;
    top = temp;
    return top;
}

void pop(node *head)
{
    if (isnull())
    {
        printf("stack underflow.\n");
        exit(1);
    }

    node *del = head;
    while (del->next->next != NULL)
    {
        del = del->next;
    }
    free(top);
    top = del;
    count--;
}

int count_node()
{
    return count;
}

int top_pos()
{
    printf("the top is at pos : %d\n", count);
    printf("data at top is : %d\n", top->data);
}

void traverse(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    system("cls");
    system("color a");

    node *head = malloc(sizeof(node));
    head->data = 10;
    top = head;
    count++;
    top = push(top, 50);
    top = push(top, 30);
    top = push(top, 40);
    top = push(top, 90);
    traverse(head);
    printf("\ncount : %d\n", count_node());

    pop(head);
    printf("count : %d\n", count_node());
    // traverse(head);

    return 0;
}
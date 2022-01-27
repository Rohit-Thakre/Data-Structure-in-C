#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node Node;

Node *circularSingly(int data)
{

    Node *temp = malloc(sizeof(Node));
    temp->data = data;
    temp->next = temp;
    temp->prev = temp;
    return temp;
}

void display(Node *tail)
{
    if (tail == NULL)
    {
        printf("the node is empty.");
    }

    else if (tail->next == tail->next->next)
    {
        printf("%d\n", tail->data);
    }
    else
    {
        Node *ptr = tail->next;

        do
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        } while (ptr != tail->next);
    }
}

Node *add_at_end(Node *tail, int data)
{
    Node *temp = circularSingly(data);
    temp->prev = tail;
    temp->next = tail->next;
    tail->next = temp;
    tail = temp;
    return tail;
}

void del_first(Node *tail)
{
    Node *temp = tail->next;

    tail->next = temp->next;
    temp->next->prev = tail;

    free(temp);
    temp = NULL;
}

int main()
{
    system("cls");
    system("color a");

    int data = 89;
    Node *tail = NULL;
    tail = circularSingly(data);

    tail = add_at_end(tail, 90);
    tail = add_at_end(tail, 91);
    tail = add_at_end(tail, 92);
    tail = add_at_end(tail, 93);
    display(tail);

    printf("\n\nafter deletion of first node.\n");
    del_first(tail);
    display(tail);
    return 0;
}
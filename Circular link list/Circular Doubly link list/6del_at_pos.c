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

void del_at_pos(Node *tail, int pos)
{
    // this code will not work for deleting first and last node.
    // for it u have to use del_first and del_lst function
    Node *temp = tail->next;

    while (pos != 1)
    {
        temp = temp->next;
        pos--;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

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

    printf("\n\nafter deletion of last node.\n");
    // tail = del_last(tail);
    del_at_pos(tail, 2);
    display(tail);
    return 0;
}
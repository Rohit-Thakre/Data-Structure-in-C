#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node Node;

Node *circularSingly(int data)
{
    Node *temp = malloc(sizeof(Node));
    temp->data = data;
    temp->next = temp;
    return temp;
}

void display(Node *tail)
{

    if (tail == NULL)
        return printf("the link list is empty.");

    else if (tail->next == tail)
        return printf("%d", tail->data);
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
    temp->next = tail->next;
    tail->next = temp;
    tail = temp;
    return tail;
}

Node *del_last(Node *tail)
{
    Node *temp = tail->next;

    while (temp->next != tail)
    {
        temp = temp->next;
    }

    temp->next = tail->next;
    free(tail);
    tail = temp;
    return tail;
}
int main()
{
    system("cls");
    system("color a");

    Node *tail = circularSingly(10);
    tail = add_at_end(tail, 20);
    tail = add_at_end(tail, 30);
    tail = add_at_end(tail, 40);
    tail = add_at_end(tail, 50);
    printf("before deletion:\n");
    display(tail);

    tail = del_last(tail);

    printf("\n\nafter deletion:\n");
    display(tail);

    return 0;
}
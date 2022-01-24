#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node Node;
int Node_count = 1;
// here node count may not correct always, due to it is initialized with 1
// it simply means there is always one node in link list, whether it is created or not,
// if there is nodes created more than one this will be accurate.

Node *circularSingly(int data)
{
    Node *temp = malloc(sizeof(Node));
    temp->data = data;
    temp->next = temp;
    // Node_count++;
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
        int cnt = 1;

        do
        {
            printf("%d: %d\n", cnt, ptr->data);
            ptr = ptr->next;
            cnt++;
        } while (ptr != tail->next);
    }
}

Node *add_at_end(Node *tail, int data)
{
    Node *temp = circularSingly(data);
    temp->next = tail->next;
    tail->next = temp;
    tail = temp;
    Node_count++;
    return tail;
}

Node *del_at_pos(Node *tail, int pos)
{
    Node *del = NULL, *temp = tail->next;
    if (pos == 1)
    {
        // this is code of fel first node func.
        tail->next = temp->next;
        free(temp);
        temp = NULL;
        return tail;
    }
    else if (pos == Node_count)
    {
        // this is code of del last node function.
        while (temp->next != tail)
        {
            temp = temp->next;
        }

        temp->next = tail->next;
        free(tail);
        tail = temp;
        return tail;
    }
    else
    {
        pos--;
        while (pos != 1)
        {
            temp = temp->next;
            pos--;
        }

        del = temp->next;
        temp->next = del->next;
        free(del);
        del = NULL;
        return tail;
    }
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

    int pos = 4;
    tail = del_at_pos(tail, pos);
    printf("\n\nafter deleting pos :%d\n", pos);
    display(tail);

    return 0;
}
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
        int cnt = 0;

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

int search_index(Node *tail, int element)
{
    Node *temp = tail->next;
    int index = 0;

    do
    {
        if (temp->data == element)
            return index;
        temp = temp->next;
        index++;
    } while (temp != tail->next);

    printf("\n\nthe element is not found in link list");
    return -1;
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
    display(tail);

    int element = 660;
    printf("\n\n%d  is at pos :%d\n", element, search_index(tail, element));

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
typedef struct node Node;

void count_node(Node *hd)
{
    int count = 0;
    if (hd == NULL)
        // return count;
        printf("there are 0 nodes.\n");

    else
    {
        Node *cp_head;
        cp_head = hd;
        while (cp_head != NULL)
        {
            count++;
            cp_head = cp_head->link;
        }
        // return count;
        printf("there are %d nodes.\n", count);
    }
}
void traverse(Node *head)
{
    if (head == NULL)
        printf("the link list is empty\n");

    else
    {
        Node *cp_head;
        cp_head = head;
        printf("the link list's data is : \n");
        while (cp_head != NULL)
        {
            printf("%d\n", cp_head->data);
            cp_head = cp_head->link;
        }
    }
}

Node *fst_insert(Node *head, int data)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->link = head;
    head = new_node;
    return head;
}

int main()
{
    system("cls");
    system("color a");

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

    printf("before insertion.\n");
    count_node(head);
    traverse(head);

    int data;
    printf("\n\nEnter your data here to insert at the first node of the link list.\n");
    scanf("%d", &data);

    head = fst_insert(head, data);
    count_node(head);
    traverse(head);

    return 0;
}
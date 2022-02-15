#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *top = NULL;

typedef struct node Node;

int count = 0;
Node *head, *temp = NULL;

Node *create(int data)
{

    temp = malloc(sizeof(Node));

    if (temp == NULL)
        printf("sorry stack overflow.\nUnable to assign memory.\n");

    else
    {
        temp->data = data;
        temp->next = NULL;
        count++;
        return temp;
    }
}

Node *push(int data)
{
    temp = create(data);
    temp->next = head;
    head = temp;
    return temp;
}

Node *pop()
{
    temp = head;
    head = head->next;
    free(temp);
    temp = NULL;
    count--;
    return head;
}

void traverse()
{
    temp = head;
    while (temp != NULL)
    {
        printf("|  %d  |\n", temp->data);
        temp = temp->next;
    }
    printf(" ------\n");
}

int main()
{
    system("cls");
    system("color a");

    while (1)
    {
        printf("please select one of your's chooice.\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Traverse\n");
        printf("4.Node counts | stack no. of nodes\n");
        printf("5.Exit\n");

        short int option = 0;
        printf("\nplease enter your option\n");
        scanf("%d", &option);
        int data;
        switch (option)
        {
        case 1:
            printf("Please enter your int data:\n");
            scanf("%d", &data);

            head = push(data);
            break;

        case 2:
            head = pop(head);
            printf("the last element is deleted successfully.\n\n");
            break;

        case 3:
            printf("the Stack's elements are: \n");
            traverse(head);
            break;

        case 4:
            printf("their are %d nodes in stack.\n\n", count);
            break;

        case 5:
            exit(1);

        default:
            printf("\nsorry invalid option.\n\n");
            break;
        }
    }
    return 0;
}
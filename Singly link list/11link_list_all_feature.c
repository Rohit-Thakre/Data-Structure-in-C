#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
typedef struct node Node;

Node *head, *temp = NULL, *ptr, *new_node = NULL;
// create_new_Node(int val);
int val = NULL, pos = 0;

/* 
this function is for creating new node, 
it  has no direct call from main. */
Node *create_new_Node()
{
    printf("Enter your value to insert in node.");
    scanf("%d", &val);
    Node *node = malloc(sizeof(Node));

    if (node == NULL)
        printf("The node doesn't got memmory\n");

    else
    {
        node->data = val;
        node->link = NULL;
        return node;
    }
}

Node *add_first_node()
{

    new_node = create_new_Node(val);

    if (head == NULL)
    {
        head = new_node;
        printf("values added at first position of link list.\n");
        return head;
    }
    else
    {
        new_node->link = head;
        head = new_node;
        printf("values added at first position of link list.\n");
        return head;
    }
}

void add_at_end()
{
    new_node = create_new_Node();
    ptr = head;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }

    ptr->link = new_node;
    ptr = NULL;

    printf("values added at last position of link list.\n");
}

void add_at_pos()
{
    printf("Enter the position where you want to new node:");
    scanf("%d", &pos);
    new_node = create_new_Node();
    ptr = head;
    printf("values added at : %d position of link list.\n", pos);

    pos--;
    while (pos != 1 && pos)
    {
        ptr = ptr->link;
        pos--;
    }

    new_node->link = ptr->link;
    ptr->link = new_node;
    ptr = NULL;
}

Node *del_first()
{
    temp = head;
    head = head->link;
    free(temp);
    temp = NULL;
    printf("first node of link list is deleted \n");
    return head;
}

void del_last()
{
    ptr = head;
    while (ptr->link->link != NULL)
        ptr = ptr->link;

    temp = ptr->link;
    ptr->link = NULL;
    free(temp);
    temp = NULL;
    printf("last node of link list is deleted \n");
}

void del_at_pos()
{
    printf("Enter the which position were you want to delete :");
    scanf("%d", &pos);
    ptr = head;
    printf("the value node at position : %d is deleted successfully !\n", pos);
    pos--;
    while (pos != 1 && pos)
    {
        ptr = ptr->link;
        pos--;
    }
    ptr->link = ptr->link->link;
    free(ptr->link->link);
    ptr->link->link = NULL;
}

void del_whole_list()
{

    while (head != NULL)
    {
        temp = head;
        head = head->link;
        free(temp);
        temp = NULL;
    }

    printf("the whole link list is deleted successfully !\n");
}

Node *link_reverse()
{
    if (head == NULL)
        printf("the list list is empty, so can't reverse it!\n");

    else if (head->link == NULL)
        printf("In list list there is only one node, so no need to reverse it.\n");

    else
    {
        Node *temp2;
        while (head != NULL)
        {
            temp2 = head->link;
            head->link = temp;
            temp = head;
            head = temp2;
        }

        head = temp;
        temp = NULL;
        printf("link list reversed successfully !");
        return head;
    }
}

int count_nodes()
{

    if (head == NULL)
        return printf("The link list is empty\n");

    else if (head->link == NULL)
        return printf("There is only one node in link list.\n");
    else
    {
        ptr = head;
        int count = 0;
        while (ptr != NULL)
        {
            ptr = ptr->link;
            count++;
        }

        return printf("In link list there is : %d nodes. \n", count);
    }
}

Node *traverse()
{
    if (head == NULL)
        printf("The link list is empty\n");

    else
    {
        ptr = head;
        printf("The link list's data is : \n [");
        while (ptr != NULL)
        {
            printf("\t%d", ptr->data);
            ptr = ptr->link;
        }
        printf("\t]\n");
        ptr = NULL;
        return head;
    }
}

void all_option()
{
    printf("1. Add node at first.\n");
    printf("2. Add node at last.\n");
    printf("3. Add node at any position.\n");
    printf("4. Delete first node.\n");
    printf("5. Delete last node.\n");
    printf("6. Delete node at any position.\n");
    printf("7. Delete whole list.\n");
    printf("8. Reverse the link list.\n");
    printf("9. Count number of nodes. \n");
    printf("10. Display list.\n");
    printf("11. Display all the option\n");
}

int main()
{
    system("cls");
    system("color a");

    short int ans = 1;

    all_option();
    // this function will show all above having option.

    // this while loop will runs until the ans is 1 or any other integer constant.
    while (ans)
    {

        printf("\nWhich operation would you like to do in singly link list.\n");
        int option;
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            add_first_node();
            break;

        case 2:
            add_at_end();
            break;

        case 3:
            add_at_pos();
            break;

        case 4:
            del_first();
            break;

        case 5:
            del_last();
            break;

        case 6:
            del_at_pos();
            break;

        case 7:
            del_whole_list();
            break;

        case 8:
            link_reverse();
            break;

        case 9:
            // printf("there are %d nodes in link list.", count_nodes());
            count_nodes();
            break;

        case 10:
            traverse();
            break;

        case 11:
            all_option();
            break;

        default:
            printf("invalid choise ! \n");
            break;
        }

        printf("\n\nWould you like to do another operation on link list: ?\n0:no, 1:yes\n");
        scanf("%d", &ans);
    }

    return 0;
}

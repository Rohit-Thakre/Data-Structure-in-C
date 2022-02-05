#include <stdio.h>
#define max 5

stack_Arr[max];
int top = -1;

int isFull()
{
    if (top == max - 1)
        return 1;

    else
        return 0;
}

int isEmpty()
{
    if (top == -1)
        return 1;

    else
        return 0;
}
void push(int data)
{
    if (/* top == max - 1 */ isFull())
    {
        printf("stack overflow\n");
        // exit(1);
    }

    else
    {
        top++;
        stack_Arr[top] = data;
        printf("data inserted successfully.\n");
    }
}

int pop()
{
    if (isEmpty())
    {
        printf("stack underflow\n");
        return -1;
    }
    else
    {
        int val;

        val = stack_Arr[top];
        top--;
        return val;
    }
}

void print()
{
    for (int i = top; i >= 0; i--)
        printf("%d ", stack_Arr[i]);

    printf("\n");
}

int main()
{
    system("cls");
    system("color a");

    while (1)
    {
        printf("\nPlease select one of the operation given below:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3.Print top\n");
        printf("4.Print Full stack\n");
        printf("5. Exit\n\n");
        int option, data;
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("please enter your data to insert:\n");
            scanf("%d", &data);
            push(data);
            break;

        case 2:
            printf("%d is popped from stack\n", pop());
            break;

        case 3:
            printf("at top there is : %d\n", stack_Arr[top]);
            break;

        case 4:
            print();
            break;

        case 5:
            exit(1);
            break;

        default:
            printf("invalid option selected.\n");
            break;
        }
    }

    return 0;
}
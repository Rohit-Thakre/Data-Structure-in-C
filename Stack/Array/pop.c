/* //  with top variable 
int stack_Arr[5], top = -1;

int pop()
{
    int val;
    val = stack_Arr[top];
    top--;
    return val;
} */

// without top variable
#include <stdio.h>
#define max 5

int stack_Arr[max], first = -1;

void push(int data)
{
    first++;
    for (int i = first; i > 0; i--)
        stack_Arr[i] = stack_Arr[i - 1];

    stack_Arr[0] = data;
}

int pop()
{
    int val, i;
    val = stack_Arr[0];

    for (i = 0; i < first; i++)
        stack_Arr[i] = stack_Arr[i + 1];

    printf("\nelement deleted successfully.\n");
    first--;
    return val;
}

void print()
{
    for (int i = 0; i <= first; i++)
        printf("%d ", stack_Arr[i]);
    printf("\n");
}

int main()
{
    system("cls");
    system("color a");
    push(1);
    push(2);
    push(3);
    print();

    printf("\n%d  deleted.\n", pop());
    print();

    return 0;
}
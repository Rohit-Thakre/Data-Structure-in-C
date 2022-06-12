// swap()
// display()
// int get_index()
// int set()
// int max()
// int min()
// int sum()
// int avg()
// left_shift()
// right_shift()
// reverse()
// isSorted()
// rotation()
// insert() // sorterd array
// merge() // 2 arrays

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int a[], int size)
{
    for (int i = 0; i < size; i++)
        printf(" %d ", a[i]);
}
int get_index(int A[], int size, int data)
{
    for (int i = 0; i < size; i++)
        if (A[i] == data)
            return i + 1;
    return -1;
}

void set(int a[], int size, int index, int data)
{
    if (index >= 0 && index < size)
        a[index] = data;
}

int max(int *a, int size)
{
    int max = 0; // for positive integers only;
    for (int i = 0; i < size; i++)
        if (max < a[i])
            max = a[i];

    return max;
}

void reverse(int a[], int size)
{
    int i = 0, j = size;

    for (i, j; i < j; i++, j--)
    {
        swap(&a[i], &a[j]);
    }
}

void left_shift(int *a, int size)
{
    int i = 0;
    while (i < size - 1)
    {
        a[i] = a[i + 1];
        i++;
    }
    a[size - 1] = 0;
}

void right_shift(int a[], int size)
{
    for (int i = size; i >= 0; i--)
    {
        a[i + 1] = a[i];
    }
    a[0] = 0;
}

void rotation(int *a, int size)
{
    int lst = a[size - 1];
    for (int i = size; i >= 0; i--)
    {
        a[i + 1] = a[i];
    }
    a[0] = lst;
}
int main()
{
    system("cls");
    system("color a");

    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;

    // printf("the index is : %d\n", get_index(A, size, 8));

    // set(A, size, 5, 99);
    // display(A, size);

    // display(A, size);
    // printf("Max is : %d\n", max(A, size));

    // reverse(A, size - 1);
    // display(A, size);

    // left_shift(A, size);
    // right_shift(A, size);

    rotation(A, size);
    display(A, size);
    return 0;
}
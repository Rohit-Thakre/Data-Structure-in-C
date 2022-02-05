int stack_Arr[5], top = -1;

void print()
{
    for (int i = top; i >= 0; i--)
        printf("%d ", stack_Arr[i]);
    printf("\n");
}
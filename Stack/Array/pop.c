
int stack_Arr[5], top = -1;

int pop()
{
    int val;
    val = stack_Arr[top];
    top--;
    return val;
}
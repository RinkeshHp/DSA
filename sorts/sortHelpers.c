void swap(int *x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void displayArray(int arr[], size_t size)
{
    for(int i = 0; i < size; ++i)
        printf("%d\t",arr[i]);
}
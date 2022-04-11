#include <stdio.h>

void selectionSort(int arr[], size_t size)
{
    int i,j;
    for(i = 0; i < size - 1; ++i)
    {
        int minpos = i;
        for(j = i + 1; j < size ; ++j)
        {
            if(arr[j] < arr[minpos])
            {
                minpos = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minpos];
        arr[minpos] = temp;
    }
}


int main(void)
{
    int arr[] = {1,2,3,-1};
    selectionSort(arr, sizeof(arr)/sizeof(int));
    for(int i = 0; i < sizeof(arr)/sizeof(int); ++i)
        printf("%d\t",arr[i]);

    return 0;
}

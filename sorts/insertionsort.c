#include <stdio.h>

void insertionSort(int arr[], size_t size)
{
    int i,j;
    for(i = 1; i < size ; ++i)
    {
        int temp = arr[i];
        for(j = i; j > 0; --j)
        {
            if(temp < arr[j-1])
            {
                arr[j] = arr[j-1];
            }
            else
            {
                break;
            }
        }
        arr[j] = temp;
    }
}

int main(void)
{
    int arr[] = {1,2,3,5,0,-1,-2,-3, 100012, 34, 124};
    insertionSort(arr, sizeof(arr)/sizeof(int));
    for(int i = 0; i < sizeof(arr)/sizeof(int); ++i)
        printf("%d\t",arr[i]);

    return 0;
}

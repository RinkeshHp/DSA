#include <stdio.h>

void stableSelectionSort(int arr[], size_t size)
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
        // stabilizer
        int temp = arr[minpos];
        for(j = minpos; j > 0; --j)
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
    int arr[] = {1,2,3,5,0,-1,-2,-3};
    bubbleSort(arr, sizeof(arr)/sizeof(int));
    for(int i = 0; i < sizeof(arr)/sizeof(int); ++i)
        printf("%d\t",arr[i]);

    return 0;
}
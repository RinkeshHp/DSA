#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int arr[], size_t size)
{
    int i,j;
    bool swap = false;
    for(i = 0; i < size - 1; ++i)
    {
        for(j = 0; j < size - i - 1; ++j)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swap = true;
            }
        }
        if(!swap){
            break;
        }
    }
}

int main(void)
{
    int arr[] = {1,2,3,5,0,-1,-2,-3};
    bubbleSort(arr, sizeof(arr)/sizeof(int));
    for(int i = 0; i < sizeof(arr)/sizeof(int); ++i)
        printf("%d",arr[i]);

    return 0;
}

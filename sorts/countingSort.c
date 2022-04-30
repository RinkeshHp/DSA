#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void displayArray(int arr[], size_t size)
{
    for (unsigned int i = 0; i < size; ++i)
        printf("%d\t", arr[i]);
    printf("\n");
}

void countingSort(int arr[], size_t n)
{
    // find max,min elements from array
    int max = INT_MIN, min = INT_MAX;
    for (unsigned int i = 0; i < n; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    // allocate array of size max - min + 1 to store counts 
    int* count = calloc((max - min + 1), sizeof(int));
    for (unsigned int i = 0; i < n; ++i)
    {
        ++(*(count + arr[i] - min));
    }
    // copy elements in sorted manner back to arr
    unsigned int k = 0;
    for (unsigned int i = 0; i < max - min + 1; ++i)
    {
        if (*(count + i) > 0) {
            unsigned int c = *(count + i);
            for (unsigned int j = 0; j < c; ++j)
            {
                arr[k++] = i + min;
            }
        }
    }
    free(count);
}

int main()
{
    int arr[] = { 1,2,3,5, 9, 0, 9, 3, -88, -64 };
    countingSort(arr, sizeof(arr) / sizeof(int));
    displayArray(arr, sizeof(arr) / sizeof(int));
    return 0;
}
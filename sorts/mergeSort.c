#include <stdio.h>

int min(int x, int y)
{ 
    return x < y ? x : y; 
}

void displayArray(int arr[], size_t size)
{
    for (unsigned int i = 0; i < size; ++i)
        printf("%d\t", arr[i]);
    printf("\n");
}

void merge(int arr[], unsigned int left, unsigned int right, unsigned int mid)
{
    unsigned int i, j, k;
    const unsigned int n1 = mid - left + 1;
    const unsigned int n2 =  right - mid;
    
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1+ j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }
 
    while (i < n1)
    {
        arr[k++] = L[i++];
    }
 
    while (j < n2)
    {
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], size_t n)
{
    for(unsigned int stepSize = 1; stepSize <= n; stepSize *= 2)
    {
        for(unsigned int left = 0; left < n; left += 2*stepSize)
        {
            merge(arr, left, min(left + 2*stepSize - 1, n-1), min(left + stepSize - 1, n-1));
        }
    }
}

int main()
{
    int arr[] = { 1,2,3,5,0,-1,4,7,9,-2,-3 };
    mergeSort(arr,sizeof(arr) / sizeof(int));
    displayArray(arr, sizeof(arr) / sizeof(int));
    return 0;
}
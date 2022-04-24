#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void displayArray(int arr[], size_t size)
{
    for (int i = 0; i < size; ++i)
        printf("%d\t", arr[i]);
    printf("\n");
}

unsigned int getNMinNMax(int arr[], unsigned int lb, unsigned int ub)
{
    unsigned int a = rand() % (ub - lb + 1) + lb, b = rand() % (ub - lb + 1) + lb, c = rand() % (ub - lb + 1) + lb;
    // printf("%d %d %d \n", a,b,c);
    // getchar();
    // inefficient comparisons incoming, brace yourselves
    if (arr[a] >= arr[b] && arr[a] < arr[c]) return a;
    else if (arr[b] >= arr[a] && arr[b] < arr[c]) return b;
    else return c;
}

unsigned int partition(int arr[], unsigned int lb, unsigned int ub)
{
    // pivot selection mania(select necessarily from array elements)
    // 1)middle element
    // swap(&arr[lb + (ub - lb)/2], &arr[lb]);
    // 2)neither smallest nor largest
    // swap(&arr[getNMinNMax(arr,lb,ub)], &arr[lb]);
    // 3)random
    swap(&arr[rand() % (ub - lb + 1) + lb], &arr[lb]);
    // 4)1st element(no optimisation)
    int pivot = arr[lb];
    unsigned int down = lb + 1, up = ub;
    while (down <= up)
    {
        while (arr[down] <= pivot)
            down++;
        while (arr[up] > pivot)
            up--;
        if (down < up)
            swap(&arr[down], &arr[up]);
    }
    arr[lb] = arr[up];
    arr[up] = pivot;
    return up;
}

void quickSort(int arr[], unsigned int lb, unsigned int ub)
{
    // life saving typecasting, ub can underflow to -1 and cause the program to break
    while ((int)lb < (int)ub)
    {
        unsigned int pivot = partition(arr, lb, ub);
        // recurse for smaller part
        if (pivot - lb < ub - pivot)
        {
            quickSort(arr, lb, pivot - 1);
            lb = pivot + 1;
        }
        else
        {
            quickSort(arr, pivot + 1, ub);
            ub = pivot - 1;
        }
    }
}

int main()
{
    int arr[] = { 1,2,3,5,0,-1,-2,-3 };
    srand(time(NULL));
    quickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
    displayArray(arr, sizeof(arr) / sizeof(int));
    return 0;
}

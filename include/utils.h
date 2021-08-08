#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

void swap(int *v, int i, int j)
{
    //cout << "swapping " << i << " " << j << endl;
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void populateArrayAscending(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = i;
    }
}

void populateArrayDescending(int *arr, int size)
{

    for (int i = 0; i < size; i++)
    {
        arr[i] = size - i - 1;
    }
}

void populateArrayRandom(int *arr, int size, int seed)
{
    srand(seed);
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100 + 1;
    }
}

double meanTime(double *arr, int size)
{
    double sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }

    return sum / size;
}

int compareDouble(const void *a, const void *b)
{
    if (*(double *)a < *(double *)b)
        return -1;
    if (*(double *)a == *(double *)b)
        return 0;
    if (*(double *)a > *(double *)b)
        return 1;
}

double medianTime(double *arr, int size)
{
    qsort(arr, size, sizeof(double), compareDouble);
    return (arr[14] + arr[15]) / 2;
}
#include <iostream>

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
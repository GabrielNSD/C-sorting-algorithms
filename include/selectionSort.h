#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "utils.h"

void selectionSortOP(int **v, int size)
{
    int *sorted = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        int iSmaller = 0;
        for (int j = 0; j < size; j++)
        {
            if ((*v)[j] < (*v)[iSmaller])
            {
                iSmaller = j;
            }
        }
        sorted[i] = (*v)[iSmaller];
        (*v)[iSmaller] = INT_MAX;
    }
    (*v) = sorted;
}

void selectionSortIP(int *v, int size)
{
    for (int i = 0; i < (size - 1); i++)
    {
        int iSmaller = i;
        for (int j = i + 1; j < size; j++)
        {
            if (v[j] < v[iSmaller])
            {
                iSmaller = j;
            }
        }
        swap(v, i, iSmaller);
    }
}
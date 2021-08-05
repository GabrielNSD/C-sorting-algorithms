#include <stdio.h>
//#include "./utils.h"

void bubbleSort(int *v, int n)
{
    for (int sweep = 0; sweep < n - 1; sweep++)
    {
        bool swapped = false;
        for (int i = 0; i < n - sweep; i++)
        {
            if (v[i] > v[i + 1])
            {
                swap(v, i, i + 1);
                swapped = true;
            }
        }
        if (swapped == false)
            return;
    }
}
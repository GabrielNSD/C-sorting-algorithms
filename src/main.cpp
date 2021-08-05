#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "selectionSort.h"
#include "bubbleSort.h"

using namespace std;

int main()
{
    int size = 100000;
    int original[size];
    int v[size];
    int k[size];
    for (int i = 0; i < size; i++)
    {
        int temp = rand() % 10 + 1;
        original[i] = temp;
        v[i] = temp;
        k[i] = temp;
    }
    int *t;
    t = k;

    double time_spent_SSIP = 0.0;

    clock_t begin_SSIP = clock();

    selectionSortIP(v, size);

    clock_t end_SSIP = clock();

    time_spent_SSIP += (double)(end_SSIP - begin_SSIP) / CLOCKS_PER_SEC;

    cout << time_spent_SSIP << endl;

    double time_spent_SSOP = 0.0;

    clock_t begin_SSOP = clock();

    selectionSortOP(&t, size);

    clock_t end_SSOP = clock();

    time_spent_SSOP += (double)(end_SSOP - begin_SSOP) / CLOCKS_PER_SEC;

    cout << time_spent_SSOP << endl;

    cout << "oi" << endl;
    cout << "[";
    for (int i = 0; i < size; i++)
    {

        //cout << v[i] << " ";
    }
    cout << "]";
    cout << endl;
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        //cout << t[i] << " ";
    }
    cout << "]";
}
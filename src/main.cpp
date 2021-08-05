#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "selectionSort.h"
#include "bubbleSort.h"
#include "insertionSort.h"
#include "mergeSort.h"
#include "quickSort.h"

using namespace std;

int main()
{
    int size = 100000;
    int original[size];
    int v[size];
    int k[size];
    int bbs[size];
    int is[size];
    int ms[size];
    int qs[size];
    for (int i = 0; i < size; i++)
    {
        int temp = rand() % 10 + 1;
        original[i] = temp;
        v[i] = temp;
        k[i] = temp;
        bbs[i] = temp;
        is[i] = temp;
        ms[i] = temp;
        qs[i] = temp;
    }
    int *t;
    t = k;

    /* double time_spent_SSIP = 0.0;

    clock_t begin_SSIP = clock();

    selectionSortIP(v, size);

    clock_t end_SSIP = clock();

    time_spent_SSIP += (double)(end_SSIP - begin_SSIP) / CLOCKS_PER_SEC;

    cout << time_spent_SSIP << "<- Selection Sort In Place" << endl;

    //inicio selection Sort O P
    double time_spent_SSOP = 0.0;

    clock_t begin_SSOP = clock();

    selectionSortOP(&t, size);

    clock_t end_SSOP = clock();

    time_spent_SSOP += (double)(end_SSOP - begin_SSOP) / CLOCKS_PER_SEC;

    cout << time_spent_SSOP << "<- Selection Sort Out of Place" << endl;
    //fim selection Sort O P

    //inicio bubble sort
    double time_spent_BBS = 0.0;

    clock_t begin_BBS = clock();

    bubbleSort(bbs, size);

    clock_t end_BBS = clock();

    time_spent_BBS += (double)(end_BBS - begin_BBS) / CLOCKS_PER_SEC;

    cout << time_spent_BBS << "<- Bubble Sort" << endl;
    //fim bubble sort */

    //inicio insertion sort
    double time_spent_IS = 0.0;

    clock_t begin_IS = clock();

    insetionSort(is, size);

    clock_t end_IS = clock();

    time_spent_IS += (double)(end_IS - begin_IS) / CLOCKS_PER_SEC;

    cout << time_spent_IS << "<- Insertion Sort" << endl;
    //fim insertion sort

    //inicio merge sort
    double time_spent_MS = 0.0;

    clock_t begin_MS = clock();

    mergeSort(ms, size);

    clock_t end_MS = clock();

    time_spent_MS += (double)(end_MS - begin_MS) / CLOCKS_PER_SEC;

    cout << time_spent_MS << "<- merge Sort" << endl;
    //fim merge sort

    //inicio quick sort
    double time_spent_QS = 0.0;

    clock_t begin_QS = clock();

    quickSort(qs, 0, size - 1);

    clock_t end_QS = clock();

    time_spent_QS += (double)(end_QS - begin_QS) / CLOCKS_PER_SEC;

    cout << time_spent_QS << "<- quick Sort" << endl;
    //fim quick sort

    cout << "oi" << endl;
    /* cout << "[";
    for (int i = 0; i < size; i++)
    {

        cout << original[i] << " ";
    }
    cout << "]";
    cout << endl;
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        cout << qs[i] << " ";
    }
    cout << "]"; */
}
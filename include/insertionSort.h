void insertionSort(int *v, int size)
{
    for (int i = 1; i < size; i++)
    {
        int valor = v[i];
        int j;
        for (j = i; j > 0 && v[j - 1] > valor; j--)
        {
            v[j] = v[j - 1];
        }
        v[j] = valor;
    }
}
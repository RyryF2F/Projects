#include <iostream>
#include <vector>

void mergeSort(int input[], int l, int r);
void merge(int input[], int l, int m, int r);

int main()
{
    int arr[] = {5,6,2,3,4,1};
    int size = sizeof(arr) / sizeof(int);

    mergeSort(arr, 0, size-1);

    for (int val : arr)
    {
        std::cout << val << std::endl;
    }

    return 0;
}

void mergeSort(int input[], int l, int r)
{
    if (l >= r)
        return;

    int m = (l+r) / 2;

    mergeSort(input, l, m);
    mergeSort(input, m+1, r);
    merge(input, l, m, r);
}

void merge(int input[], int l, int m, int r)
{
    int nL = m-l+1;
    int nR = r-m;

    int L[nL], R[nR];

    for (int i = 0; i < nL; i++)
    {
        L[i] = input[l+i];
    }

    for (int j = 0; j < nR; j++)
    {
        R[j] = input[m + 1 + j];
    }

    int i = 0, j = 0, k = l;

    while (i < nL && j < nR)
    {
        if (L[i] <= R[j])
        {
            input[k] = L[i];
            i++;
        }else
        {
            input[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < nL)
    {
        input[k] = L[i];
        i++;
        k++;
    }

    while (j < nR)
    {
        input[k] = R[j];
        j++;
        k++;
    }
}
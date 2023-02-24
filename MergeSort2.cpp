#include <iostream>
#include <cmath>
using namespace std;

void Merge(int *array, int low, int mid, int high)
{
    int i, j, k, leftArrSize = mid - low + 1, rightArrSize = high - mid;
    int leftArr[leftArrSize], rightArr[rightArrSize];
    for (i = 0; i < leftArrSize; i++)
        leftArr[i] = array[low + i];
    for (j = 0; j < rightArrSize; j++)
        rightArr[j] = array[(mid + 1) + j];
    i = 0;
    j = 0;
    k = low;
    while (i < leftArrSize && j < rightArrSize)
    {
        if (leftArr[i] < rightArr[j])
            array[k++] = leftArr[i++];
        else
            array[k++] = rightArr[j++];
    }
    while (i < leftArrSize)
        array[k++] = leftArr[i++];
    while (j < rightArrSize)
        array[k++] = rightArr[j++];
}

void MergeSort(int *array, int low, int high)
{
    if (low < high)
    {
        int mid = floor((high + low) / 2);
        MergeSort(array, low, mid);
        MergeSort(array, mid + 1, high);
        Merge(array, low, mid, high);
    }
}
int main()
{
    int array[9] = {9, 6, 3, 4, 2, 7, 1, 8, 5};
    MergeSort(array, 0, 9 - 1);
    for (auto element : array)
    {
        cout << element << "\t";
    }
    cout << endl;
}
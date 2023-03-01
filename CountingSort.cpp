#include <iostream>
#include <vector>
using namespace std;

int FindLargest(int array[], int size)
{
    int largestNum = array[0];
    for (int i = 0; i < size; i++)
    {
        if (array[i] > largestNum)
            largestNum = array[i];
    }
    return largestNum;
}

int CountingSort(int *array, int size)
{
    int sizeOfIndicesArray = FindLargest(array, size);
    int i, j, k, l, m, arrayOfIndices[sizeOfIndicesArray], sortedArray[size];
    for (i = 0; i <= sizeOfIndicesArray; i++)
        arrayOfIndices[i] = 0;

    for (j = 0; j < size; j++)
        arrayOfIndices[array[j]]++;

    for (k = 1; k <= sizeOfIndicesArray; k++)
        arrayOfIndices[k] += arrayOfIndices[k - 1];

    for (l = size - 1; l >= 0; l--)
    {
        sortedArray[arrayOfIndices[array[l]] - 1] = array[l];
        arrayOfIndices[array[l]]--;
    }
    for (m = 0; m < size; m++)
    {
        array[m] = sortedArray[m];
    }
}

int main()
{
    int array[5] = {6, 5, 4, 3, 9000};
    CountingSort(array, 5);
    for (int element : array)
        cout << element << "\t";

    cout << endl;
}
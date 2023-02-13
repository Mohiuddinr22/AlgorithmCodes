#include <iostream>
using namespace std;

void Merge(int *array, int low, int high, int mid)
{
    int i, j, k, leftArraySize, rightArraySize;
    leftArraySize = mid - low + 1;
    rightArraySize = high - mid;
    int leftArray[leftArraySize], rightArray[rightArraySize];
    for (i = 0; i < leftArraySize; i++)
        leftArray[i] = array[low + i];
    for (j = 0; j < rightArraySize; j++)
        rightArray[j] = array[mid + j + 1];
    i = 0;
    j = 0;
    k = low;
    while (i < leftArraySize && j < rightArraySize)
    {
        if (leftArray[i] <= rightArray[j])
        {
            array[k] = leftArray[i];
            i++;
        }
        else
        {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }
    while (i < leftArraySize)
    {
        array[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < rightArraySize)
    {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

void MergeSort(int *array, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        MergeSort(array, low, mid);
        MergeSort(array, mid + 1, high);
        Merge(array, low, high, mid);
    }
}

void DisplayArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << "\t";
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter the size of your array : ";
    cin >> size;
    int array[size];
    cout << "Enter "<<size<<" elements of your array : " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    cout << "Here's the array you entered : ";
    DisplayArray(array, size);
    MergeSort(array, 0, size - 1);
    cout << "Here's the sorted array      : ";
    DisplayArray(array, size);

    return 0;
}
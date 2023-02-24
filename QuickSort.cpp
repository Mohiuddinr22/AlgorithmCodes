#include <iostream>
using namespace std;

void DisplayArray(int *array, int size)
{
    for (int i = 0; i < size; i++)

        cout << array[i] << "\t";

    cout << endl;
}

int Partition(int *array, int low, int high, int pivot)
{
    int pivotIndex = low;
    for (int i = low; i <= high; i++)
    {
        if (array[i] <= pivot)
        {
            swap(array[i], array[pivotIndex]);
            pivotIndex++;
        }
    }
    pivotIndex--;
    return pivotIndex;
}

void QuickSort(int *array, int low, int high)
{
    if (low <= high)
    {
        int pivot = array[high];
        int pivotIndex = Partition(array, low, high, pivot);
        QuickSort(array, low, pivotIndex - 1);
        QuickSort(array, pivotIndex + 1, high);
    }
}

int main()
{
    int array[9] = {5, 9, 6, 3, 4, 2, 7, 1, 8};
    QuickSort(array, 0, 8);
    DisplayArray(array, 8 + 1);
}
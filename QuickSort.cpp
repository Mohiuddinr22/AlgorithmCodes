#include <iostream>
using namespace std;

void DisplayArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << "\t";
    }
    cout << endl;
}

void Swap(int &a, int &b)
{
    int c;
    c = a;
    a = b;
    b = c;
}

int Partition(int *array, int low, int high, int pivot)
{
    int left = low, right = high;
    while (left < right)
    {
        while (array[left] <= pivot)
            left++;

        while (array[right] >= pivot)
            right--;

        if (left < right)
            swap(array[left], array[right]);
    }
    array[low] = array[right];
    array[right] = pivot;
    return right;
}

void QuickSort(int *array, int low, int high)
{
    if (low < high)
    {
        int pivot = array[rand()];
        int pivotIndex = Partition(array, low, high, pivot);
        QuickSort(array, low, pivotIndex - 1);
        QuickSort(array, pivotIndex + 1, high);
    }
}

int main()
{
    int size;
    cout << "Enter the size of your array : ";
    cin >> size;
    int array[size];
    cout << "Enter " << size << " elements of your array : " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    cout << "Here's your array : ";
    DisplayArray(array, size);
    int l = 0, h = size - 1;

    QuickSort(array, l, h);
    cout << "Here's the sorted array : ";
    DisplayArray(array, size);
}
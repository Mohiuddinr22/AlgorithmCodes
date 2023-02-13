#include <iostream>
#include <vector>
using namespace std;

void InsertionSort(int *arr, int size)
{
    int i, j;
    for (i = 1; i <= size; i++)
    {
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j + 1], arr[j]);
            }
        }
    }
}

int main()
{
    int array[30] = {46, 37, 64, 70, 79, 90, 44, 93, 58, 33, 91, 88, 40, 50, 43, 15, 89, 26, 18, 36, 24, 62, 10, 28, 69, 92, 35, 31, 52, 27};
    // int array[9] = {6, 9, 7, 5, 2, 3, 8, 1, 4};
    InsertionSort(array, 30);
    int index = 0;
    while (index < 30)
    {
        cout << array[index] << " ";
        index++;
    }
    cout << endl;
}
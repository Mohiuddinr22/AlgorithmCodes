#include <iostream>
#include <vector>
using namespace std;

void InsertionSort(int *array, int size)
{
    int i, j, carry;
    for (i = 0; i < size; i++)
    {
        carry = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > carry)
        {
            swap(array[j], array[j + 1]);
            j--;
        }
        array[j + 1] = carry;
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
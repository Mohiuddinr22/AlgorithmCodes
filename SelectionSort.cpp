#include <iostream>
using namespace std;

void DisplayArray(int *array, int size)
{
    int index = 0;
    while (index < size)
    {
        cout << array[index] << " ";
        index++;
    }
    cout << endl;
}

void SelectionSort(int *array, int size)
{
    int i, j, carry;
    for (i = 0; i < size - 1; i++)
    {
        carry = i;
        j = i + 1;
        while (j < size)
        {
            if (array[j] > array[i])
            {
                carry = j;
            }
            j++;
        }
        swap(array[carry], array[j]);
    }
}

int main()
{
    int array[15] = {159, 419, 418, 204, 406, 102, 300, 458, 364, 343, 295, 394, 334, 211, 455};
    SelectionSort(array, 15);
    DisplayArray(array, 15);
}
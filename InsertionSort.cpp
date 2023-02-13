#include <iostream>
#include <vector>
using namespace std;

void InsertionSort(int *arr, int size)
{
    int i, j, k, carry;
    for (i = 1; i < sizeof(arr); i++)
    {
        carry = arr[i];
        for (j = i - 1; j < sizeof(arr); j--)
        {
            if (arr[j] < arr[i] && i != j)
            {
                carry = arr[j];
            }
        }
        swap(carry, arr[i]);
    }
}

int main()
{
    return 0;
}
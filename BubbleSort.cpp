#include <iostream>
using namespace std;

void BubbleSort(unsigned short *array, int size)
{
    int i, j, flag;
    for (i = 1; i < size; i++)
    {
        for (j = 0; j < size - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
                flag = 1;
            }
        }
    }
    if (flag == 0)
        return;
}

int main()
{
    unsigned short array[10];
    for (int i = 0; i < sizeof(array); i++)
    {
        array[i] = rand() % 100 + 1;
    }
    BubbleSort(array, 10);
    for (int j = 0; j < 10; j++)
    {
        cout << array[j] << "\t";
    }
    cout << endl;
}
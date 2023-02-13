#include <iostream>
#include <vector>
using namespace std;

void BubbleSort(vector<int> &arr, int size)
{
    int i, j, flag;

    for (i = 1; i < arr.size(); i++)
    {
        for (j = 0; j < arr.size() - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            return;
        }
    }
}

int main()
{
    vector<int> array;
    int size, element;
    cout << "Enter the size of your array : ";
    cin >> size;
    cout << endl
         << "Enter the elements of your array : " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> element;
        array.push_back(element);
    }
    cout << "Your array is : ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << "\t";
    }
    cout << endl;
    BubbleSort(array, size);
    cout << "Here is the sorted array : ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << "\t";
    }
    cout << endl;
    return 0;
}
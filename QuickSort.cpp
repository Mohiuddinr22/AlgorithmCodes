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
        int pivot = array[low];
        int pivotIndex = Partition(array, low, high, pivot);
        QuickSort(array, low, pivotIndex - 1);
        QuickSort(array, pivotIndex + 1, high);
    }
}

int main()
{
    int array[100] = {291, 296, 144, 344, 452, 919, 424, 449, 713, 779, 629, 260, 458, 455, 526, 335, 282, 923, 731, 753, 901, 340, 233, 298, 398, 882, 921, 603, 517, 559, 977, 791, 479, 983, 942, 841, 165, 123, 203, 507, 719, 750, 232, 550, 489, 196, 808, 385, 800, 487, 416, 824, 755, 283, 782, 241, 469, 659, 612, 781, 694, 131, 439, 676, 854, 994, 239, 622, 838, 303, 886, 867, 609, 157, 506, 415, 663, 860, 403, 265, 579, 903, 221, 686, 498, 362, 292, 280, 610, 711, 730, 237, 364, 604, 820, 697, 608, 160, 553, 529};
    QuickSort(array, 0, 100 - 1);
    DisplayArray(array, 100);
}
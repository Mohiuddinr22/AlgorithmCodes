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
    int i, j, k;
    for (i = 0; i < size - 1; i++)
    {
        k = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[k])
            {
                k = j;
            }
        }
        if (i != k)
            swap(array[i], array[k]);
    }
}

int main()
{
    int array[100] = {291, 296, 144, 344, 452, 919, 424, 449, 713, 779, 629, 260, 458, 455, 526, 335, 282, 923, 731, 753, 901, 340, 233, 298, 398, 882, 921, 603, 517, 559, 977, 791, 479, 983, 942, 841, 165, 123, 203, 507, 719, 750, 232, 550, 489, 196, 808, 385, 800, 487, 416, 824, 755, 283, 782, 241, 469, 659, 612, 781, 694, 131, 439, 676, 854, 994, 239, 622, 838, 303, 886, 867, 609, 157, 506, 415, 663, 860, 403, 265, 579, 903, 221, 686, 498, 362, 292, 280, 610, 711, 730, 237, 364, 604, 820, 697, 608, 160, 553, 529};
    SelectionSort(array, 100);
    DisplayArray(array, 100);
}
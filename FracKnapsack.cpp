#include <iostream>
#include <array>
using namespace std;

struct item
{
public:
    int weight;
    double ratio, benefit;
    item() {}
    item(double benefit, int weight) : benefit(benefit), weight(weight)
    {
        this->ratio = this->benefit / (double)this->weight;
    }
};

int SortByRatio(item items[], int size)
{
    int i, j, k;
    for (int i = 0; i < size - 1; i++)
    {
        k = i;
        for (j = i + 1; j < size; j++)
            if (items[j].ratio > items[k].ratio)
                k = j;

        if (i != k)
            swap(items[i], items[k]);
    }
}

double FractionalKnapsack(item items[], int size, int weightCap)
{
    double currBenefit = 0.0;

    SortByRatio(items, size);

    int i = 0, currWeight = 0;

    while (currWeight < weightCap)
    {
        if (currWeight < weightCap)
        {
            currWeight += items[i].weight;
            currBenefit += items[i].benefit;
            i++;
        }
        if (currWeight >= weightCap)
            return currBenefit - (double)(currWeight - weightCap) * items[i - 1].ratio;
    }
}

int main()
{
    item A = item(25, 18);
    item B = item(15, 10);
    item C = item(24, 15);

    item items[4] = {A, B, C};

    cout << FractionalKnapsack(items, 3, 20) << endl;
}

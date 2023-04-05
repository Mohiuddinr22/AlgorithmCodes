#include <bits/stdc++.h>
using namespace std;

struct item
{
public:
    int value, weight;
    item(int val, int wei) : value(val), weight(wei) {}
};

int knapsack(vector<item> &items, int weightCap)
{
    int val = 0, currWeight = 0;
    for (int i = 0; i < items.size(); i++)
    {
        val += items[i].value;
        currWeight += items[i].weight;
        if(currWeight)
    }
}

int main()
{
}
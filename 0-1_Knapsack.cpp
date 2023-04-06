#include <bits/stdc++.h>
using namespace std;

struct item
{
public:
    int value, weight;
    item(int wei, int val) : weight(wei), value(val) {}
};

int knapsack(vector<item> &items, int weightCap)
{
    int **matrix = new int *[items.size() + 1];
    for (int i = 0; i <= items.size(); i++)
    {
        matrix[i] = new int[weightCap + 1];
        for (int j = 0; j <= weightCap; j++)
            matrix[i][j] = 0;
    }
    for (int i = 1; i <= items.size(); i++)
    {
        int k = 0;
        for (int j = 0; j <= weightCap; j++)
        {
            if (j < items[i - 1].weight)
                matrix[i][j] = matrix[i - 1][j];
            else
                matrix[i][j] = max(items[i - 1].value + matrix[i - 1][j - items[i - 1].weight], matrix[i - 1][j]);
            k++;
        }
    }
    for (int i = 0; i <= items.size(); i++)
    {
        for (int j = 0; j <= weightCap; j++)
        {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
    return matrix[items.size()][weightCap];
}

int main()
{
    item i1(10, 100);
    item i2(40, 280);
    item i3(20, 120);
    // item i4(7, 10);
    vector<item> items = {i1, i2, i3};
    cout << knapsack(items, 60);
}
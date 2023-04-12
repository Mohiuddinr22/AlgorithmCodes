#include <bits/stdc++.h>
using namespace std;

void findLCS(string &a, string &b)
{
    vector<vector<int>> matrix(a.length() + 1, vector<int>(b.length()));
    for (int i = 0; i <= a.length(); i++)
        for (int j = 0; j <= b.length(); j++)
            matrix[i][j] = 0;
    for (int i = 1; i <= a.length(); i++)
        for (int j = 1; j <= b.length(); j++)
        {
            if (a[i - 1] == b[j - 1])
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            else
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
        }
    for (int i = 0; i <= a.length(); i++)
    {
        for (int j = 0; j <= b.length(); j++)
            cout << matrix[i][j] << "  ";
        cout << endl;
    }
    stack<char> stack;
    int i = a.length(), j = b.length();
    while (i > 0 && j > 0)
    {
        if (matrix[i][j] == matrix[i - 1][j])
        {
            i--;
            continue;
        }
        else if (matrix[i][j] != matrix[i][j - 1] && matrix[i][j] == matrix[i - 1][j - 1] + 1)
        {
            cout << "[" << i << "," << j << "]" << endl;
            stack.push(a[i - 1]);
            i--;
        }
        j--;
    }
    string ans = "";
    while (!stack.empty())
    {
        ans += stack.top();
        stack.pop();
    }
    cout << "Your longest common subsequence is : " << ans << endl;
}

int main()
{
    string s1, s2;
    cout << "Enter first word : ";
    cin >> s1;
    cout << "Enter second word : ";
    cin >> s2;
    findLCS(s2, s1);
}
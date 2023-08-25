#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("cost.txt", "r", stdin);
    int n = 4;
    vector<vector<int>> costM(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            if (x == -1)
            {
                x = 1e9;
            }
            costM[i][j] = x;
        }
    }
    for (int via = 0; via < n; via++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                costM[i][j] = min(costM[i][j], (costM[i][via] + costM[via][j]));
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (costM[i][j] >= 1e9)
            {
                costM[i][j] = -1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << costM[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
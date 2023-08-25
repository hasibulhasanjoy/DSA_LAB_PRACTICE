#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int m = 4;
    vector<vector<int>> adjacentMatrix(m, vector<int>(m));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> adjacentMatrix[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < m; k++)
            {
                adjacentMatrix[i][j] = adjacentMatrix[i][j] or
                                       (adjacentMatrix[i][k] and adjacentMatrix[k][j]);
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << adjacentMatrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> multi(vector<vector<int>> &a, vector<vector<int>> &b)
{
    int row = a.size();
    int col = a[0].size();
    int n = col;
    vector<vector<int>> result(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            for (int k = 0; k < n; k++)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}

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
    vector<vector<vector<int>>> res;
    res.push_back(adjacentMatrix);
    for (int i = 1; i < m; i++)
    {
        vector<vector<int>> temp = multi(res[i - 1], adjacentMatrix);
        res.push_back(temp);
    }
    // path of len 2
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "From " << i << " to " << j << " : " << res[1][i][j] << endl;
        }
    }
    vector<vector<int>> b(m, vector<int>(m, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < m; k++)
            {
                b[i][j] += res[k][i][j];
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
void print(int row, int col, vector<vector<int>> arr)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void addition(int row, int col, vector<vector<int>> &arr, vector<vector<int>> &add)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            add[i][j] = add[i][j] + arr[i][j];
        }
    }
}

void subtraction(int row, int col, vector<vector<int>> &arr, vector<vector<int>> &sub)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sub[i][j] = sub[i][j] - arr[i][j];
        }
    }
}

void multiplication(int row, int col, vector<vector<int>> &arr, vector<vector<int>> &mul)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            for (int k = 0; k < row; k++)
            {
                mul[i][j] += arr[i][k] * arr[k][j];
            }
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    int row = 5, col = 5;
    vector<vector<int>> arr(row, vector<int>(col));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
    print(row, col, arr);
    vector<vector<int>> add(row, vector<int>(col, 0));
    addition(row, col, arr, add);
    print(row, col, add);
    vector<vector<int>> sub(row, vector<int>(col, 0));
    subtraction(row, col, arr, sub);
    print(row, col, sub);
    vector<vector<int>> mul(row, vector<int>(col, 0));
    multiplication(row, col, arr, mul);
    print(row, col, mul);
    return 0;
}
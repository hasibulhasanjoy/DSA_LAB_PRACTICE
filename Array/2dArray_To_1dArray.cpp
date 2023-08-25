#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int row = 5, col = 4;
    int arr[row][col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
    int size = row * col;
    int arr1[size];
    int k = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr1[k++] = arr[i][j];
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    int group = 5;
    int start = (group - 1) * col;
    int end = start + col;
    for (int i = start; i < end; i++)
    {
        cout << arr1[i] << " ";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    // Taking 1 base index for simple calculation
    int n = 22;
    int arr[n];
    arr[0] = 0;
    for (int i = 1; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int row = 3, col = 2;
    int previousRow = ((row - 1) * row) / 2; // total element from 1st to previous row
    int l = previousRow + col;               // index of the given data
    cout << arr[l] << endl;
    // print all data of a given row
    row = 6;
    previousRow = ((row - 1) * row) / 2;
    int start = previousRow + 1; // starting index
    int end = start + row;       // ending index
    for (int i = start; i < end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
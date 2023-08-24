#include <bits/stdc++.h>
using namespace std;
void insertINSortedArray(int arr[], int size, int data)
{
    int index = 0;
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] > 54)
        {
            index = i;
            break;
        }
    }
    for (int j = 9; j >= index; j--)
    {
        arr[j + 1] = arr[j];
    }
    arr[index] = data;
}
void insertAtGivenIndex(int arr[], int index, int data)
{
    int size = 11;
    for (int i = size - 1; i >= index - 1; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index - 1] = data;
}
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    freopen("input.txt", "r", stdin);
    int arr[100];
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }
    print(arr, 10);
    insertINSortedArray(arr, 10, 54);
    print(arr, 11);
    insertAtGivenIndex(arr, 5, 100);
    print(arr, 12);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int tree[100];
void insert(int data)
{
    int index = 0;
    while (tree[index] != -1)
    {
        if (data > tree[index])
        {
            index = (2 * index) + 2;
        }
        else if (data < tree[index])
        {
            index = (2 * index) + 1;
        }
        else
        {
            cout << "found at index " << index << endl;
            return;
        }
    }
    tree[index] = data;
}
void inorder(int index, int size)
{
    if (tree[index] == -1)
    {
        return;
    }
    inorder(2 * index + 1, size);
    cout << tree[index] << " ";
    inorder(2 * index + 2, size);
}
int main()
{
    freopen("input.txt", "r", stdin);
    for (int i = 0; i < 100; i++)
    {
        tree[i] = -1;
    }
    int i;
    cin >> i;
    int cnt = 0;
    while (i != -1)
    {
        insert(i);
        cin >> i;
        cnt++;
    }
    for (int i = 0; i < cnt; i++)
    {
        cout << tree[i] << " ";
    }
    cout << endl;
    inorder(0, cnt);
    return 0;
}
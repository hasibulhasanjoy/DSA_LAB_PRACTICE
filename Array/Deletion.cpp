#include <bits/stdc++.h>
using namespace std;
void print(char s[][50], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << s[i] << endl;
    }
    cout << endl;
}
void deleteFromGivenIndex(char s[][50], int index, int size)
{
    for (int i = index; i < size - 1; i++)
    {
        strcpy(s[i], s[i + 1]);
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    char s[20][50];
    for (int i = 0; i < 5; i++)
    {
        cin >> s[i];
    }
    print(s, 5);
    deleteFromGivenIndex(s, 2, 5);
    print(s, 4);
    return 0;
}
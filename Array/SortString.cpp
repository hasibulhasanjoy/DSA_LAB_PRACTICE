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
void bubbleSort(char s[][50], int size)
{
    char temp[50];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (strcmp(s[j], s[j + 1]) > 0)
            {
                strcpy(temp, s[j]);
                strcpy(s[j], s[j + 1]);
                strcpy(s[j + 1], temp);
            }
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    char s[20][50];
    for (int i = 4; i >= 0; i--)
    {
        cin >> s[i];
    }
    print(s, 5);
    bubbleSort(s, 5);
    print(s, 5);
    return 0;
}
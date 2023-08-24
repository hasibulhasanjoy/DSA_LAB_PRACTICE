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
int linearSearch(char s[][50], char key[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(s[i], key) == 0)
        {
            return i;
        }
    }
    return -1;
}
int binarySeach(char s[][50], char key[], int size)
{
    int start = 0;
    int end = size - 1;
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (strcmp(s[mid], key) == 0)
        {
            return mid;
        }
        else if (strcmp(s[mid], key) > 0)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}
int main()
{
    freopen("input.txt", "r", stdin);
    char s[20][50];
    char key[] = "absjogjaaa";
    for (int i = 0; i < 5; i++)
    {
        cin >> s[i];
    }
    print(s, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << linearSearch(s, s[i], 5) << endl;
        cout << binarySeach(s, s[i], 5) << endl;
    }
    cout << linearSearch(s, key, 5) << endl;
    cout << binarySeach(s, key, 5) << endl;
    return 0;
}
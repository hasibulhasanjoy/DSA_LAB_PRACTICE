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

void insertIntoSorted(char s[][50], char data[], int size)
{
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(s[i], data) > 0)
        {
            index = i;
            break;
        }
        else
            index++;
    }
    for (int i = size - 1; i >= index; i--)
    {
        strcpy(s[i + 1], s[i]);
    }
    strcpy(s[index], data);
}
void insertAtGivenIndex(char s[][50], char data[], int index, int size)
{
    for (int i = size - 1; i >= index; i--)
    {
        strcpy(s[i + 1], s[i]);
    }
    strcpy(s[index], data);
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
    insertIntoSorted(s, "rahim", 5);
    print(s, 6);
    insertAtGivenIndex(s, "karim", 5, 6);
    print(s, 7);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
void towerOfHanoi(int n, string src, string dest, string help)
{
    if (n == 0)
    {
        return;
    }
    // move top n - 1 disk from src to help using dest.
    // then move n-1 disk from help to dest using src
    towerOfHanoi(n - 1, src, help, dest);
    cout << src << " --> " << dest << endl;
    towerOfHanoi(n - 1, help, dest, src);
}
int main()
{
    string src = "A", dest = "C", help = "B";
    towerOfHanoi(3, src, dest, help);
    return 0;
}
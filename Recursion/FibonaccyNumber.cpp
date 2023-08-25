#include <bits/stdc++.h>
using namespace std;
long long int fibCache[70];
long long int fib(int n)
{
    if (n <= 1)
        return n;
    if (fibCache[n] != 0)
        return fibCache[n];
    fibCache[n] = fib(n - 1) + fib(n - 2);
    return fibCache[n];
}

int main()
{
    for (int i = 0; i < 51; i++)
    {
        cout << fib(i) << " ";
    }
    return 0;
}
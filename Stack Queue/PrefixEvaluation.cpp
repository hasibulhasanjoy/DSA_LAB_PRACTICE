#include <iostream>
#include <math.h>
using namespace std;

class Stack
{
private:
    int size;
    int *arr;
    int index;

public:
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        index = -1;
    }
    void push(int data)
    {
        if (index >= size)
        {
            cout << "Stack over flow " << endl;
            return;
        }
        arr[++index] = data;
    }
    int top()
    {
        return arr[index];
    }
    void pop()
    {
        if (index < 0)
        {
            cout << "stack under flow" << endl;
            return;
        }
        index--;
    }
    bool isEmpty()
    {
        if (index < 0)
        {
            return true;
        }
        return false;
    }
    int Stacksize()
    {
        return max(0, index + 1);
    }
};

bool isOperator(char c)
{
    if (c == '+' or c == '-' or c == '*' or c == '/' or c == '(' or c == ')' or c == '^')
        return true;
    return false;
}

int getEvaluation(int a, int b, char c)
{
    if (c == '+')
        return a + b;
    if (c == '-')
        return a - b;
    if (c == '*')
        return a * b;
    if (c == '/')
        return a / b;
    if (c == '^')
        return pow(a, b);
}

int prefixEvaluation(string s)
{
    Stack st(1000);
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (!isOperator(s[i]))
        {
            st.push(s[i] - '0');
        }
        else
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            int result = getEvaluation(a, b, s[i]);
            st.push(result);
        }
    }
    return st.top();
}

int main()
{
    string prefix = "-+7*45+20";
    cout << prefixEvaluation(prefix) << endl;
    return 0;
}
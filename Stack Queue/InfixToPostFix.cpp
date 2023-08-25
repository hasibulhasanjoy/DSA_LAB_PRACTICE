#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    int size;
    char *arr;
    int index;

public:
    Stack(int size)
    {
        this->size = size;
        arr = new char[size];
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
    bool empty()
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
    if (c == '+' or c == '-' or c == '*' or c == '/' or c == '^' or c == '(' or c == ')')
        return true;
    return false;
}

int precedency(char c)
{
    if (c == '^')
        return 3;
    if (c == '*' or c == '/')
        return 2;
    if (c == '+' or c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string s)
{
    Stack st(1000);
    string post = "";
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (!isOperator(c))
        {
            post += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.empty() and st.top() != '(')
            {
                post += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() and precedency(st.top()) >= precedency(c))
            {
                post += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty())
    {
        post += st.top();
        st.pop();
    }
    return post;
}

int main()
{
    string infix = "k+l-m*n+(o^p)*w/u/v*t+q";
    string postfix = infixToPostfix(infix);
    cout << postfix << endl;
    return 0;
}
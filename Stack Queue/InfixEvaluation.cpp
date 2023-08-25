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

int operatorPrecedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

int infixEvaluation(string s)
{
    Stack op(1000);
    Stack num(1000);
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (!isOperator(c))
        {
            num.push(c - '0');
        }
        else if (c == '(')
        {
            op.push(c);
        }
        else if (c == ')')
        {
            while (op.top() != '(')
            {
                char ch = op.top();
                op.pop();
                int b = num.top();
                num.pop();
                int a = num.top();
                num.pop();
                int result = getEvaluation(a, b, ch);
                num.push(result);
            }
            op.pop();
        }
        else
        {
            while (!op.empty() and op.top() != '(' and
                   operatorPrecedence(op.top()) >= operatorPrecedence(c))
            {
                char ch = op.top();
                op.pop();
                int b = num.top();
                num.pop();
                int a = num.top();
                num.pop();
                int result = getEvaluation(a, b, ch);
                num.push(result);
            }
            op.push(c);
        }
    }
    while (!op.empty())
    {
        char ch = op.top();
        op.pop();
        int b = num.top();
        num.pop();
        int a = num.top();
        num.pop();
        int result = getEvaluation(a, b, ch);
        num.push(result);
    }
    return num.top();
}

int main()
{
    string infix = "2+(5-3*6/2)";
    cout << infixEvaluation(infix) << endl;
    return 0;
}
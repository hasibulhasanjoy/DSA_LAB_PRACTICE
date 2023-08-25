#include <iostream>
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

int main()
{
    Stack st(10);
    cout << st.Stacksize() << endl;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout << st.Stacksize() << endl;
    while (!st.isEmpty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}
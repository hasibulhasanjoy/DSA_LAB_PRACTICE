#include <iostream>
using namespace std;

class Queue
{
private:
    int size;
    int *arr;
    int index;
    int rear;

public:
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        rear = 0;
        index = 0;
    }
    void push(int data)
    {
        if (rear >= size)
        {
            cout << "queue is full" << endl;
            return;
        }
        arr[rear++] = data;
    }
    int front()
    {
        return arr[index];
    }
    void pop()
    {
        if (rear == index)
        {
            cout << "queue is empty" << endl;
            return;
        }
        index++;
    }
    bool empty()
    {
        if (rear == index)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Queue q(5);
    // cout << q.empty() << endl;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
    q.pop();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Heap
{
private:
    int size;
    vector<int> heap;

public:
    Heap()
    {
        heap.push_back(-1);
        size = 0;
    }
    void insert(int data)
    {
        size++;
        heap.push_back(data);
        int index = size;
        while (index > 1)
        {
            int parent = index / 2;
            if (heap[parent] < heap[index])
            {
                swap(heap[parent], heap[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i < size; i++)
        {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.insert(52);
    h.print();
    return 0;
}
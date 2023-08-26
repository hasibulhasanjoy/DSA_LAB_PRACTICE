#include <bits/stdc++.h>
using namespace std;

class Hash
{
private:
    int size;
    int *arr;
    int hashFunction(int key)
    {
        return key % size;
    }
    int linear_prob(int index, int key)
    {
        int i = 1;
        while (arr[(index + i) % size] != -1)
        {
            i++;
        }
        return (index + i) % size;
    }

public:
    Hash(int size)
    {
        this->size = size;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = -1;
        }
    }
    void insert(int key)
    {
        int index = hashFunction(key);
        if (arr[index] == -1)
        {
            arr[index] = key;
            return;
        }
        else
        {
            index = linear_prob(index, key);
            arr[index] = key;
        }
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << i << " " << arr[i] << endl;
        }
    }
    int search(int key)
    {
        int index = hashFunction(key);
        int original = index;
        int i = 1;
        while (arr[index] != -1)
        {
            if (arr[index] == key)
                return index;
            index = (original + i) % size;
            if (original == index)
                break;
        }
        return -1;
    }
};

int main()
{
    vector<int> data = {54, 26, 93, 17, 77, 31, 44, 55, 20};
    Hash h(11);
    for (auto i : data)
    {
        h.insert(i);
    }
    h.print();
    cout << h.search(26);
}
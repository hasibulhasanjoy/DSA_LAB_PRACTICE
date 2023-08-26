#include <bits/stdc++.h>
using namespace std;

class HashTable
{
private:
    int size;
    vector<int> table;

    int hashFunction(int key)
    {
        return key % size;
    }

    int linear_prob(int index, int key)
    {
        int step = 3;
        int i = 0;
        while (table[(index + i * step) % size] != -1)
        {
            i++;
        }
        return (index + i * step) % size;
    }

public:
    HashTable(int size)
    {
        this->size = size;
        table.resize(size, -1);
    }
    void insert(vector<int> data)
    {
        for (int i = 0; i < data.size(); i++)
        {
            int index = hashFunction(data[i]);
            if (table[index] == -1)
            {
                table[index] = data[i];
            }
            else
            {
                index = linear_prob(index, data[i]);
                table[index] = data[i];
            }
        }
    }
    int search(int key)
    {
        int index = hashFunction(key);
        int originalIndex = index;
        int i = 1;
        while (table[index] != -1)
        {
            if (table[index] == key)
            {
                return index;
            }
            index = (originalIndex + i) % size;
            i += 3;
            if (index == originalIndex)
            {
                break;
            }
        }
        return -1;
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << i << " " << table[i] << endl;
        }
    }
};

int main()
{
    vector<int> data = {54, 26, 93, 17, 77, 31, 44, 55, 20};
    HashTable h(11);
    h.insert(data);
    h.display();
    cout << h.search(54) << endl;
    return 0;
}
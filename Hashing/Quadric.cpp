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

    int quadric(int index, int attempt)
    {
        int step = attempt * attempt;
        return (index + step) % size;
    }

public:
    HashTable(int size)
    {
        this->size = size;
        table.resize(size, -1);
    }
    void insert(vector<int> &data)
    {
        for (auto item : data)
        {
            int index = hashFunction(item);
            int i = 1;
            while (table[index] != -1)
            {
                index = quadric(index, i);
                i++;
            }
            table[index] = item;
        }
    }
    int search(int key)
    {
        int index = hashFunction(key);
        int original = index;
        int i = 1;
        while (table[index] != -1)
        {
            if (table[index] == key)
            {
                return index;
            }
            index = (original + i) % size;
            i++;
            if (original == index)
            {
                break;
            }
        }
        return -1;
    }
    void display()
    {
        for (int key = 0; key < size; key++)
        {
            cout << "key : " << key << " Data : " << table[key] << endl;
        }
    }
};

int main()
{
    vector<int> data = {54, 26, 93, 17, 77, 31, 44, 55, 20};
    HashTable h(11);
    h.insert(data);
    h.display();
    cout << h.search(77) << endl;
    return 0;
}
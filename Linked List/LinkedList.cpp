#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string data;
    Node *next;
    Node(string data)
    {
        this->data = data;
        next = NULL;
    }
};
class LinkedList
{
private:
    Node *head, *lastNode;

public:
    LinkedList()
    {
        head = NULL;
        lastNode = NULL;
    }
    void addNode(string data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            lastNode = newNode;
            return;
        }
        lastNode->next = newNode;
        lastNode = lastNode->next;
    }
    void print()
    {
        Node *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << " " << endl;
            ptr = ptr->next;
        }
        cout << endl;
    }
    void insertAtSortedPosition(string data)
    {
        Node *newNode = new Node(data);
        if (newNode->data < head->data)
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node *current = head;
        Node *nextptr = head->next;
        while (nextptr)
        {
            if (nextptr->data > newNode->data)
            {
                break;
            }
            current = current->next;
            nextptr = nextptr->next;
        }
        current->next = newNode;
        newNode->next = nextptr;
    }
    void deleteFromSortedList(string data)
    {
        if (head->data == data)
        {
            Node *temp = head;
            head = head->next;
            delete (temp);
            return;
        }
        Node *p1 = head;
        Node *p2 = head->next;
        while (p2 and p2->data != data)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = p2->next;
        delete (p2);
    }
    bool search(string data)
    {
        Node *p1 = head;
        while (p1)
        {
            if (p1->data == data)
            {
                return true;
            }
            p1 = p1->next;
        }
        return false;
    }
};
int main()
{
    LinkedList l;
    l.addNode("abcd");
    l.addNode("efgh");
    l.addNode("ijkl");
    l.addNode("mnop");
    l.print();
    l.insertAtSortedPosition("aabcd");
    l.insertAtSortedPosition("iabd");
    l.insertAtSortedPosition("zajf");
    l.print();
    l.deleteFromSortedList("aabcd");
    l.print();
    cout << l.search("ijkl") << endl;
    cout << l.search("aabcd") << endl;
    return 0;
}
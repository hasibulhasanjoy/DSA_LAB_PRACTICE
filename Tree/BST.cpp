#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    cout << endl;
}
bool Search(Node *root, int key)
{
    if (root == NULL)
        return false;
    if (root->data == key)
        return true;
    if (key < root->data)
        return Search(root->left, key);
    else
        return Search(root->right, key);
}
void inOrderTraversal(Node *root)
{
    // Left -> Node(print) -> Right
    if (root == NULL)
    {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (Search(root, data))
    {
        cout << "element is already present" << endl;
        return root;
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}
int main()
{
    freopen("input.txt", "r", stdin);
    int i;
    Node *root = NULL;
    cin >> i;
    while (i != -1)
    {
        root = insert(root, i);
        cin >> i;
    }
    insert(root, 18);
    levelOrder(root);
    inOrderTraversal(root);
    cout << endl;
    cout << Search(root, 22) << " " << Search(root, 50) << endl;
    insert(root, 18);
    return 0;
}
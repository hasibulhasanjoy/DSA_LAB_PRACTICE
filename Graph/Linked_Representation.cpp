#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int v;
    Node *next;
    Node(int d)
    {
        v = d;
        next = NULL;
    }
};

class Graph
{
private:
    int num;
    Node **adjlist;

public:
    Graph(int n)
    {
        num = n;
        adjlist = new Node *[n];
        for (int i = 0; i < n; i++)
        {
            adjlist[i] = NULL;
        }
    }
    void addEdge(int u, int v)
    {
        Node *newNode = new Node(v);
        newNode->next = adjlist[u];
        adjlist[u] = newNode;

        newNode = new Node(u);
        newNode->next = adjlist[v];
        adjlist[v] = newNode;
    }
    void bfs(int startNode)
    {
        bool *visited = new bool[num];
        for (int i = 0; i < num; i++)
        {
            visited[i] = false;
        }
        queue<int> q;
        q.push(startNode);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            cout << cur << " ";
            visited[cur] = true;
            Node *ad = adjlist[cur];
            while (ad)
            {
                int data = ad->v;
                if (visited[data] == false)
                {
                    q.push(data);
                    visited[data] = true;
                }
                ad = ad->next;
            }
        }
    }
    void dfs(int startNode)
    {
        bool *visited = new bool[num];
        for (int i = 0; i < num; i++)
        {
            visited[i] = false;
        }
        stack<int> s;
        s.push(startNode);
        visited[startNode] = true;
        while (!s.empty())
        {
            int c = s.top();
            s.pop();
            cout << c << " ";
            Node *cur = adjlist[c];
            while (cur)
            {
                int data = cur->v;
                if (visited[data] == false)
                {
                    s.push(data);
                    visited[data] = true;
                }
                cur = cur->next;
            }
        }
    }
    void printList()
    {
        for (int i = 0; i < num; i++)
        {
            Node *cur = adjlist[i];
            cout << "vertex : " << i << " : ";
            while (cur)
            {
                cout << cur->v << " ";
                cur = cur->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    int node = 5, edge = 5;
    Graph g(node);
    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    g.printList();
    g.bfs(0);
    cout << endl;
    g.dfs(0);
    return 0;
}
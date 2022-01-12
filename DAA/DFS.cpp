#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    map<int, bool> visited;
    map<int, list<int>> adj;

    void addEdge(int v, int w);

    void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFS(int v)
{

    visited[v] = true;
    cout << v << " ";

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

int main()
{
    Graph g;
    int e;
    cout << "Enter the No. edges to be connected" << endl;
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        cout << "Enter the vertices to be connected" << endl;
        int x, y;
        cin >> x >> y;
        g.addEdge(x, y);
    }

    cout << "Enter the vertex as a start" << endl;
    int vertex;
    cin >> vertex;
    cout << "Following is Depth First Traversal"
            " (starting from vertex "
         << vertex << ")" << endl;

    g.DFS(vertex);
    cout << endl; 
    cout << "Program developed by Rishabh Agnihotri Scholar No. 20U02073" << endl;
    return 0;
}

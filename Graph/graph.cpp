#include <bits/stdc++.h>
using namespace std;

void print_DFS(int **edges, int n, int sv, bool *visited)
{
    cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (sv == i)
        {
            continue;
        }
        if (edges[sv][i] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            print_DFS(edges, n, i, visited);
        }
    }
}

void print_BFS(int **edges, int n, int sv, bool *visited)
{
    queue<int> q;
    q.push(sv);
    visited[sv] = true;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        cout << front << endl;
        for (int i = 0; i < n; i++)
        {
            if (front == i)
            {
                continue;
            }
            if (edges[front][i] == 1)
            {
                if (visited[i])
                {
                    continue;
                }
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void print_DFSDis(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            print_DFS(edges, n, i, visited);
        }
    }

    delete[] visited;
}

void print_BFSDis(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            print_BFS(edges, n, i, visited);
        }
    }
    delete[] visited;
}

bool ishasPathDFS(int **edges, int n, bool *visited, int x, int y)
{
    if (edges[x][y] == 1)
        return true;
    bool ans = false;
    visited[x] = true;
    for (int i = 0; i < n; i++)
    {
        if (x == i)
        {
            continue;
        }
        if (edges[x][i] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            ans = ishasPathDFS(edges, n, visited, i, y);
        }
        if (ans)
        {
            return true;
        }
    }

    return ans;
}

bool ishasPathBFS(int **edges, int n, bool *visited, int x, int y)
{
    if (x == y)
        return true;
    queue<int> q;
    q.push(x);
    visited[x] = true;
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (x == i)
            {
                continue;
            }
            if (edges[x][i] == 1)
            {
                if (!visited[i])
                    q.push(i);
                visited[i] = true;
            }
        }
        if (x == y)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    // Connected Graph
    // bool *visited = new bool[n];
    // for (int i = 0; i < n; i++)
    // {
    //     visited[i] = false;
    // }
    // cout << "DFS" << endl;
    // print_DFS(edges, n, 0, visited);
    // for (int i = 0; i < n; i++)
    // {
    //     visited[i] = false;
    // }
    // cout << "BFS" << endl;
    // print_BFS(edges, n, 0, visited);

    // Disconnected Graph

    // cout << "DFS" << endl;
    // print_DFSDis(edges, n);

    // cout << "BFS" << endl;
    // print_BFSDis(edges, n);

    // has Path
    int x, y;
    cin >> x >> y;

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    // if (ishasPathBFS(edges, n, visited, x, y))
    if (ishasPathDFS(edges, n, visited, x, y))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    delete[] visited;
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}

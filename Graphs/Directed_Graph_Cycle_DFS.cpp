#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool checkCYCLE_Directed_Graph_DFS(int vertex, vector<int> graph[], bool vis[], bool dfsVis[])
{
    vis[vertex] = 1;
    dfsVis[vertex] = 1;
    for (auto it : graph[vertex])
    {
        if (!vis[it])
        {
            if (checkCYCLE_Directed_Graph_DFS(it, graph, vis, dfsVis))
                return 1;
        }
        else if (dfsVis[it])
        {
            return 1;
        }
    }
    dfsVis[vertex] = 0;
    return 0;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<int> adj[V + 1];   // the vertices start from 1 acc to CN
    bool vis[V + 1] = {0};    // the vertices start from 1 acc to CN
    bool dfsVis[V + 1] = {0}; // the vertices start from 1 acc to CN
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    bool isThereCycle = false;
    for (int i = 1; i <= V; i++)
    {
        if (vis[i])
            continue;
        if (checkCYCLE_Directed_Graph_DFS(i, adj, vis, dfsVis))
        {
            isThereCycle = true;
            break;
        }
    }

    if (isThereCycle)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}
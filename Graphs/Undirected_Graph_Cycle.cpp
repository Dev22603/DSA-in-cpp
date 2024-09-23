#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool CYCLE_Undirected_Graph_BFS(int vertex, vector<int> graph[], bool vis[])
{
    vis[vertex] = 1;
    queue<pair<int, int>> q;
    q.push({vertex, -1});
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (auto adjacentNode : graph[node])
        {
            if (!vis[adjacentNode])
            {
                vis[adjacentNode] = 1;
                q.push({adjacentNode, node});
            }
            else if (parent != adjacentNode)
            {
                return 1;
            }
        }
    }
    return 0;
}
bool CYCLE_Undirected_Graph_DFS(int vertex, int parent, vector<int> graph[], bool vis[])
{
    vis[vertex] = 1;
    bool isCycleExists = 0;
    for (int i = 0; i < graph[vertex].size(); i++)
    {
        int child = graph[vertex][i];
        if (vis[child] && child == parent)
        {
            continue;
        }
        if (vis[child])
        {
            return 1;
        }
        isCycleExists |= CYCLE_Undirected_Graph_DFS(child, vertex, graph, vis);
    }
    return isCycleExists;
}
bool CYCLE_Undirected_Graph_DFS_2(int node, int parent, vector<int> adj[], vector<int> &vis)
{
    vis[node] = 1;
    for (auto adjNode : adj[node])
    {
        if (!vis[adjNode])
        {
            vis[adjNode] = 1;
            if (CYCLE_Undirected_Graph_DFS_2(adjNode, node, adj, vis))
                return true;
        }
        else if (parent != adjNode)
            return true;
    }
    return false;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<int> adj[V + 1]; // the vertices start from 1 acc to CN
    bool vis[V + 1] = {0};  // the vertices start from 1 acc to CN
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool isThereCycle = false;
    for (int i = 1; i <= V; i++)
    {
        if (vis[i])
            continue;
        if (CYCLE_Undirected_Graph_DFS(i, -1, adj, vis))
        {
            isThereCycle = true;
            break;
        }
    }
    for (int i = 1; i <= V; i++)
    {
        if (vis[i])
            continue;
        if (CYCLE_Undirected_Graph_BFS(i, adj, vis))
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
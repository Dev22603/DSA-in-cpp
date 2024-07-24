#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void dfs(int vertex, vector<int> graph[], bool vis[], vector<int> &ans)
{
    vis[vertex] = 1;
    ans.push_back(vertex);
    for (int i = 0; i < graph[vertex].size(); i++)
    {
        int child = graph[vertex][i];
        if (vis[child] == 0)
            dfs(child, graph, vis, ans);
    }
}
vector<vector<int>> DFS_Connected_Components(int V, vector<int> adj[])
{
    bool vis[V] = {0};
    vector<vector<int>> ans;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            vector<int> temp;
            dfs(i, adj, vis, temp);
            ans.push_back(temp);
        }
    }

    return ans;
}
int main()
{

    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> ans = DFS_Connected_Components(V, adj);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int it : ans[i])
        {
            cout << it << " ";
        }
        cout << endl;
    }
}
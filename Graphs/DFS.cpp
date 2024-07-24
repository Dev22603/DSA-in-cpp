#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void dfs(int vertex, vector<int> graph[], bool vis[],vector<int>&ans)
{
    vis[vertex] = 1;
    ans.push_back(vertex);
    for (int i = 0; i < graph[vertex].size(); i++)
    {
        int child = graph[vertex][i];
        if (vis[child] == 0)
            dfs(child, graph, vis,ans);
    }
    // OR this for loop

    // for (int child : graph[vertex])
    // {
    //     if (vis[child] == 0)
    //         dfs(child);
    // }
}
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    bool vis[V]={0};
    vector<int> ans1;    
    dfs(0,adj,vis,ans1);
    return ans1;
}
int main()
{

    int V, tem, E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans = dfsOfGraph(V, adj);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
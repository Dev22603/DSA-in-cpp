#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    bool vis[V] = {0};
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> BFS;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        BFS.push_back(node + 1);
        for (int i = 0; i < adj[node].size(); i++)
        // for (auto i: adj[node]) OR
        {
            if (!vis[adj[node][i]])
            {
                vis[adj[node][i]] = 1;
                q.push(adj[node][i]);
            }
        }
    }
    return BFS;
}


vector<int>bfsNode(vector<int>graph[],int V,int Vertex)
{
    vector<bool>vis(V);
    vis[Vertex] = true;
    queue<int>q;
    q.push(Vertex);
    vector<int>BFSOrder;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        BFSOrder.push_back(node+1);
        for(int i:graph[node])
        {
            if(!vis[i])
            {
                vis[i]=1;
                q.push(i+1);
            }
        }
    }
    return BFSOrder;
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
    vector<int> ans = bfsOfGraph(V, adj);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
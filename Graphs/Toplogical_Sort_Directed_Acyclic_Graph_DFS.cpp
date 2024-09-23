#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void Topological_Sort_DFS(int vertex, vector<int> graph[], bool vis[], stack<int> &st)
{
    vis[vertex] = 1;
    for (auto it : graph[vertex])
    {
        if (!vis[it])
        {
            Topological_Sort_DFS(it, graph, vis, st);
        }
    }
    st.push(vertex);
}



// interview bit
// love babbar



int main()
{
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    bool vis[V] = {0};
    stack<int> s;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            Topological_Sort_DFS(i, adj, vis, s);
        }
    }
    vector<int> Topological_Sorted_Order;
    while (!s.empty())
    {
        Topological_Sorted_Order.push_back(s.top());
        s.pop();
    }
    for (int i : Topological_Sorted_Order)
        cout << i << " ";
}
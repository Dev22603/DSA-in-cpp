#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vll vector<ll>
#define vint vector<int>
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define pll pair<ll, ll>
#define mpll map<ll, ll>
#define ld long double
#define float double
#define Y cout << "YES\n"
#define N cout << "NO\n"
#define f(i, x, n) for (ll i = x; i < n; i++)
#define rf(i, x, n) for (ll i = x; i >= n; i--)
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (ll) a.size()
#define pi (3.141592653589)
#define min3(a, b, c) min(a, min(b, c))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))
#define Upper(a) transform(a.begin(), a.end(), a.begin(), ::toupper)
#define Lower(a) transform(a.begin(), a.end(), a.begin(), ::tolower)
#define setbit(x, k) (x |= (1LL << k))
#define usetbit(x, k) (x &= ~(1LL << k))
#define checkbit(x, k) (x & (1LL << k))
#define togglebit(x, k) (x ^ (1LL << k))
#define watch(x) cerr << (#x) << " is " << (x) << endl


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
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
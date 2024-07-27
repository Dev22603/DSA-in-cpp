#include <bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution {
public:
bool check(int vertex,int V, vector<int>adj[],vector<int>&vis)
{
    queue<int>q;
    vis[vertex]=0;

    q.push(vertex);
    while(!q.empty())
    {
        int node =q.front();
        q.pop();
        for(auto it:adj[node])
        {
            if(vis[it]==-1)
            {
                vis[it]=!vis[node];
                q.push(it);
            }
            else if(vis[it]==vis[node])
            {
                return false;
            }
        }
    }
    return true;
}
	bool isBipartite(int V, vector<int>adj[]){
	        vector<int>vis(V,-1);

	    for(int i =0;i<V;i++)
	    {
	        if(vis[i]==-1 && !check(i,V,adj,vis)) return 0;
	    }
	    return 1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends
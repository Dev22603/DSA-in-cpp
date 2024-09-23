#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
    void dfs(int row, int col,vector<vector<int>>&vis,vector<pair<int,int>>&vec ,vector<vector<int>>&grid,int row0, int col0)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>delrow={1,0,-1,0};
        vector<int>delcol={0,1,0,-1};
        for(int i =0;i<4;i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1)
            {
                vec.push_back({nrow-row0,ncol-col0});
                vis[nrow][ncol]=1;
                dfs(nrow,ncol,vis,vec,grid,row0,col0);
            }
        }
        
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m));
        set<vector<pair<int,int>>>islands;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    vis[i][j]=1;
                    vector<pair<int,int>>vec;
                    dfs(i,j,vis,vec,grid,i,j);
                    islands.insert(vec);
                }
            }
        }
        return islands.size();
    }
};



int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}

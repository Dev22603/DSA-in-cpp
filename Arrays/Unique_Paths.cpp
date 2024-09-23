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


int Unique_Paths_BruteForce(int m, int n, int i, int j)
    {
        if(i==m || j==n)
        {
            return 0;
        }
        if(i==m-1 && j== n-1)
        {
            return 1;
        }
        return Unique_Paths_BruteForce(m, n,  i,  j+1) + Unique_Paths_BruteForce(m,  n, i+1, j);

    }


    int Unique_Paths_Better_DP(int m, int n, int i, int j,vector<vector<int>>&dp)
    {
        if(i==m || j==n)
        {
            return 0;
        }
        if(i==m-1 && j== n-1)
        {
            return 1;
        }
        if(dp[i][j]!=-1)return dp[i][j];

        return dp[i][j]=Unique_Paths_Better_DP(m, n,  i,  j+1,dp) + Unique_Paths_Better_DP(m,  n, i+1, j,dp);

    }



    long long nCr(int n, int r)
    {
        if (r < 0 || r > n)
            return 0;

        r = min(r, n - r); // Choose the smaller of r and n-r

        long long result = 1;
        for (int i = 1; i <= r; ++i) {
            result *= (n - i+1);
            result /= i;
        }
        // for (int i = 1; i <= r; ++i) {
        // }

        return result;
    }
    long long Unique_Paths_Optimal_Combinations(int m, int n)
    {
        int right=n-1,down=m-1,total=n+m-2;
        return nCr(total,down);
        
    }

    int uniquePaths(int m, int n) {
        return Unique_Paths_Optimal_Combinations(m,n);
        // vector<vector<int>>dp(m, vector<int>(n, -1));

        // return Unique_Paths_Better_DP(m,n,0,0,dp);
    }
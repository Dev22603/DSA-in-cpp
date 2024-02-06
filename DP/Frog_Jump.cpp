// https://www.codingninjas.com/studio/problems/frog-jump_3621012?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

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

// Recursion
// int frogJump(int n, vector<int> &heights)
// {
//     if (n <= 1)
//         return 0;
//     int left = frogJump(n - 1, heights) + abs(heights[n - 1] - heights[n - 2]);
//     int right = INT_MAX;
//     if (n > 2)
//         right = frogJump(n - 2, heights) + abs(heights[n - 1] - heights[n - 3]);
//     return min(left, right);
// }






// dp
// int frogJumpDP(int n, vector<int> &heights, vector<int> &dp)
// {
//     if (n <= 1)
//         return dp[n] = 0;
//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }
//     int left = frogJumpDP(n - 1, heights,dp) + abs(heights[n - 1] - heights[n - 2]);
//     int right = INT_MAX;
//     if (n > 2)
//         right = frogJumpDP(n - 2, heights,dp) + abs(heights[n - 1] - heights[n - 3]);
//     return dp[n] = min(left, right);
// }
// int frogJump(int n, vector<int> &heights)
// {
//     vector<int> dp(n+1,-1);
//     return frogJumpDP(n,heights,dp);
// }





int frogJumpDP(int n, vector<int> &heights, vector<int> &dp)
{
    if (n==0)
        return dp[n] = 0;
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int left = frogJumpDP(n-1, heights,dp) + abs(heights[n] - heights[n - 1]);
    int right = INT_MAX;
    if (n > 1)
        right = frogJumpDP(n - 2, heights,dp) + abs(heights[n] - heights[n - 2]);
    return dp[n] = min(left, right);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1);
    return frogJumpDP(n-1,heights,dp);
}
int main()
{
    int n=100;
}

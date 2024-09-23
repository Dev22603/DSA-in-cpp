// https://www.codingninjas.com/studio/problems/minimal-cost_8180930?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

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


int help(int n, vector<int> &height, vector<int> &dp, int k)
{
    if (n == 0)
    {
        return dp[n] = 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int minCost = INT_MAX;

    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
        {
            int cost = help(n - i, height, dp, k) + abs(height[n] - height[n - i]);
            minCost = min(minCost, cost);
        }
    }
    return dp[n] = minCost;
}

int minimizeCost(int n, int k, vector<int> &height)
{
    // Write your code here.
    vector<int> dp(n + 1, -1);
    return help(n - 1, height, dp, k);
}

int main()
{
    int n = 100;
}

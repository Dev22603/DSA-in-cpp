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

int maxProfit_BruteForce(vector<int> &prices)
{
    // Brute force O(N2)

    int n = prices.size();
    int pro = 0;
    for (int buy = 0; buy < n - 1; buy++)
    {
        for (int sell = buy + 1; sell < n; sell++)
        {
            pro = max(pro, prices[sell] - prices[buy]);
        }
    }
    return pro;
}
int maxProfit_Better(vector<int> &prices)
{
    // Optimized approach O(N) O(N)
    // We create  an auxillary array to store the max value from end
    int n = prices.size();
    vector<int> ma(n);
    ma[n - 1] = prices[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        ma[i] = max(prices[i], ma[i + 1]);
    }
    int prof = 0;
    for (int i = 0; i < n; i++)
    {
        prof = max(prof, ma[i] - prices[i]);
    }
    return prof;
}

int maxProfit_Optimal(vector<int> &prices)
{
    // Most optimized approach with O(N) time complexity and O(1) space complexity
    // we will find the minimum so far from the beginning of the array
    int MinSoFar = prices[0];
    int n = prices.size();
    int Profit = 0;
    for (int i = 0; i < n; i++)
    {
        MinSoFar = min(MinSoFar, prices[i]);
        Profit = max(prices[i] - MinSoFar, Profit);
    }
    return Profit;
}
int main()
{
    int n;
    cin >> n;
    vector<int> array(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    maxProfit_Better(array);
}

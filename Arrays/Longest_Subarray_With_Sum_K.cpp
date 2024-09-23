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
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int Length_Of_Subarray_BruteForce(vector<int> &arr, int K)
{
    int n = arr.size();
    int s = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            s=0;
            for (int k = i; k <= j; k++)
            {
                s += arr[k];
            }
            if (s == K)
            {
                ans = max((j - i + 1), ans);
            }
        }
    }
    return ans;
}
int Length_Of_Subarray_Better(vector<int> &arr, int K)
{
    int n = arr.size();
    int s = 0, ans = 0;
    vector<int> prefixSum(n + 1);
    for (int i = 1; i <= n; i++)
    {
        prefixSum[i] += prefixSum[i - 1] + arr[i - 1];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            s = prefixSum[j] - prefixSum[i];
            if (s == K)
            {
                ans = max((j - i), ans);
            }
        }
    }
    return ans;
}
int Length_Of_Subarray_Optimal_PositivesAndNegatives(vector<int> &arr, int K)
{
    int n = arr.size();
    long long s = 0;
    int ans = 0;
    map<long long, int> PrefixSum;

    for (int i = 0; i < n; i++)
    {
        s += arr[i];
        if (s == K)
        {
            ans = max(ans, i + 1);
        }
        long long rem = s - K;
        if (PrefixSum.find(rem) != PrefixSum.end())
        {
            int len = i - PrefixSum[rem];
            ans = max(len, ans);
        }
        else if (PrefixSum.find(s) == PrefixSum.end())
        {
            PrefixSum[s] = i;
        }
    }

    return ans;
}
// IMP
int Length_Of_Subarray_Optimal_NO_PositivesAndNegatives(vector<int> &arr, int K)
{
    int n = arr.size();
    long long s = 0;
    int ans = 0;
    int l = 0, r = 0;
    s = arr[r];
    while (l < n && r < n)
    {
        if (s == K)
        {
            ans = max(ans, r - l + 1);
        }
        if (s > K)
        {
            s -= arr[l];
            l++;
        }
        else if (s <= K)
        {
            s += arr[++r];
        }
    }
    return ans;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> array(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    cout << Length_Of_Subarray_Better(array, k) << endl;
}
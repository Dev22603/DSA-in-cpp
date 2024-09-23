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

vector<int> find_Missing_Repeating(vector<int> &nums)
{
    unordered_map<int, int> m;
    int n = nums.size();
    int missing = -1, repeating = -1;
    for (int i : nums)
    {
        m[i]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (m[i] == 0)
        {
            missing = i;
        }
        if (m[i] == 2)
        {
            repeating = i;
        }
    }
    return {missing, repeating};
}

vector<int> find_Missing_Repeating_Optimal(vector<int> &nums)
{
    int n=nums.size();
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (SN * (2 * n + 1)) / 3;
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++)
    {
        S += nums[i];
        S2 += (long long)nums[i] * (long long)nums[i];
    }
    long long val1 = S - SN; // x-y
    long long val2 = S2 - S2N;
    val2 = val2 / val1; // x+y
    long long x = (val1 + val2) / 2;
    long long y = x - val1;
    return {(int)y, (int)x};
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> array(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> array[i][0] >> array[i][1];
    }
    for (int i = 0; i < n; i++)
    {
        cout << array[i][0] << array[i][1] << " ";
    }
}

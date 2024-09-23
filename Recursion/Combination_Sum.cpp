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

void Combination_Optimal(int i, int n, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &temp)
{
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }
    if (i == n)
    {
        return;
    }
    if (arr[i] <= target)
    {
        temp.push_back(arr[i]);
        Combination(i, n, target - arr[i], arr, ans, temp);
        temp.pop_back();
    }
    Combination(i + 1, n, target, arr, ans, temp);
}
void Combination(int i, int n, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &temp)
{
    if (i == n)
    {
        if (target == 0)
        {
            ans.push_back(temp);
        }
        return;
    }
    if (arr[i] <= target)
    {
        temp.push_back(arr[i]);
        Combination(i, n, target - arr[i], arr, ans, temp);
        temp.pop_back();
    }
    Combination(i + 1, n, target, arr, ans, temp);
}

vector<vector<int>> combinationSum(vector<int> &arr, int k)
{

    vector<vector<int>> ans;
    vector<int> temp;
    int n = arr.size();
    Combination(0, n, k, arr, ans, temp);
    return ans;
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
}

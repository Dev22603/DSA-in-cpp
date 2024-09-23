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

int Maximum_Subarray_BruteForce(vector<int> &nums)
{
    int n = nums.size();
    int s = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            s = 0;
            for (int k = i; k <= j; k++)
            {
                s += nums[i];
            }
            ans = max(s, ans);
        }
    }
    return ans;
}
int Maximum_Subarray_Better(vector<int> &nums)
{
    int n = nums.size();
    int s = 0, ans = 0;
    ans = *max_element(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        s = 0;
        for (int j = i; j < n; j++)
        {
            s += nums[j];
            ans = max(ans, s);
        }
    }
    return ans;
}
int Maximum_Subarray_Optimal_Kadane_LC53(vector<int> &nums)
{
    int n = nums.size();
    int s = 0, ans1 = *max_element(nums.begin(), nums.end()), ans = 0;

    for (int i = 0; i < n; i++)
    {
        s += nums[i];
        ans = max(s, ans);
        if (s < 0)
        {
            // ans = max(s, ans); //We dont need this line
            s = 0;
        }
    }
    if (ans == 0)
    {
        return ans1;
    }
    return ans;
}
int Maximum_Subarray_Optimal_Kadane_CN(vector<int> &nums)
{
    int n = nums.size();
    int s = 0, ans = 0;

    for (int i = 0; i < n; i++)
    {
        s += nums[i];
        ans = max(s, ans);
        if (s < 0)
        {
            s = 0;
        }
    }
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
    cout << "Before Sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\nAfter Sorting" << endl;
    cout << Maximum_Subarray_Optimal_Kadane_LC53(array);
}
// 8
// 2 2 0 1 2 1 0 1
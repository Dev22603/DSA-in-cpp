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

int Majority_Element_BruteForce(vector<int> &nums)
{
    int n = nums.size();
    int a = n / 3;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[j] == nums[i])
            {
                cnt++;
            }
        }
        if (cnt > a)
        {
            return nums[i];
        }
    }
    return -1;
}
vector<int> Majority_Element_Better(vector<int> &nums)
{
    int n = nums.size();
    int a = n / 3;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[nums[i]]++;
    }
    vector<int> l;
    for (auto i : m)
    {
        if (i.second > a)
        {
            l.push_back(i.first);
        }
    }
    return l;
}
vector<int> Majority_Element_Optimal_Moore_Voting_Algorithm(vector<int> &nums)
{
    // IMP
    int n = nums.size();
    int a = n / 3;
    int cnt1 = 0, el1 = 0, cnt2 = 0, el2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (cnt1 == 0 && el2 != nums[i])
        {
            cnt1 = 1;
            el1 = nums[i];
        }
        else if (cnt2 == 0 && el1 != nums[i])
        {
            cnt2 = 1;
            el2 = nums[i];
        }
        else if (el1 == nums[i])
        {
            cnt1++;
        }
        else if (el2 == nums[i])
        {
            cnt2++;
        }
        else
        {
            cnt1--, cnt2--;
        }
    }
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == el1)
        {
            cnt1++;
        }
        else if (nums[i] == el2)
        {
            cnt2++;
        }
    }
    vector<int> ans;
    if (cnt1 > a)
    {
        ans.push_back(el1);
    }
    if (cnt2 > a)
    {
        ans.push_back(el2);
    }
    sort(ans.begin(), ans.end());
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

}
// 8
// 2 2 0 1 2 1 0 1
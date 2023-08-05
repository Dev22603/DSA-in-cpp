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
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

bool Sum_2_BruteForce(vector<int> &arr, int k)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == k)
                return 1;
        }
    }
    return 0;
}
string Sum_2_Better(vector<int> &arr, int k)
{
    int n = arr.size();
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        if (s.find(k - arr[i]) != s.end())
        {
            return "YES";
        }
        s.insert(arr[i]);
    }
    return "NO";
}
vector<int> twoSum_Leetcode_Better(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int> v(2);
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        if (m.find(target - nums[i]) != m.end())
        {
            v[0] = i;
            v[1] = m[target - nums[i]];
            return v;
        }
        else
        {
            m[nums[i]] = i;
        }
    }
    return v;
}

string twoSum_Read_Optimal_2_Pointer(vector<int> &nums, int target) // coding Ninjas
{
    int n = nums.size();
    int l = 0, r = n - 1, s = 0;
    sort(nums.begin(), nums.end());
    while (l < r)
    {
        s = nums[l] + nums[r];
        if (s == target)
        {
            return "YES";
        }
        else if (s > target)
        {
            s -= nums[r];
            r--;
        }
        else
        {
            s -= nums[l];
            l++;
        }
    }
    return "NO";
}
int main()
{
    int n, d;
    cin >> n >> d;
    vector<int> array(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    cout << Sum_2_Better(array, d);
}
// nums = [2,7,11,15], target = 9
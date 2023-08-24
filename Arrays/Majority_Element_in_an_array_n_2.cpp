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
        if (cnt > n / 2)
        {
            return nums[i];
        }
    }
    return -1;
}
int Majority_Element_Better(vector<int> &nums)
{
    int n = nums.size();
    int ans = 0, cnt;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[nums[i]]++;
    }
    for (auto it : m)
    {
        if (it.second > n / 2)
        {
            return it.first;
        }
    }
    return -1;
}
int Majority_Element_Optimal_Moore_Voting_Algorithm(vector<int> &nums)
{
    // IMP
    int n = nums.size();
    int cnt = 0, el = 0;
    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            cnt = 1;
            el = nums[i];
        }
        else
        {
            if (nums[i] == el)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
    }
    int cnt1=0;
    for (int i = 0; i < n; i++)
    {
        if(nums[i]==el)
        {
            cnt1++;
        }
    }
    if(cnt1>n/2)
    {
        return el;
    }
    return -1;
    

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
    cout<<Majority_Element_Optimal_Moore_Voting_Algorithm(array);
    
}
// 8
// 2 2 0 1 2 1 0 1
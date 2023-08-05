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

vector<vector<int>> Merge_Overlapping_Intervals_BruteForce(vector<vector<int>> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        int start = arr[i][0];
        int end = arr[i][1];
        // if (!ans.empty() && end<=ans.back()[1])
        // {
        //     continue;
        // }   striver wrote this if statement but I am writing the i=j statement on line 56
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j][0] <= end)
            {
                end = max(end, arr[j][1]);
            }
            else
            {
                break;
            }
            i = j; // you can use line instead of the if statement
            i++;   // you can use line instead of i=j
        }
        ans.push_back({start, end});
    }
    return ans;
}

vector<vector<int>> Merge_Overlapping_Intervals_BruteForce_Better(vector<vector<int>> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        int start = arr[i][0];
        int end = arr[i][1];
        // if (!ans.empty() && end<=ans.back()[1])
        // {
        //     continue;
        // }   striver wrote this if statement but I am writing the i=j statement on line 56
        int j;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j][0] <= end)
            {
                end = max(end, arr[j][1]);
            }
            else
            {
                break;
            }
            // i++; // you can use line instead of the if statement
        }
        i = j - 1;
        ans.push_back({start, end});
    }
    return ans;
}
vector<vector<int>> Merge_Overlapping_Intervals_Optimal(vector<vector<int>> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (ans.empty() || arr[i][0] > ans.back()[1])
            ans.push_back(arr[i]);
        else
        {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
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
    Merge_Overlapping_Intervals_Optimal(array);
}

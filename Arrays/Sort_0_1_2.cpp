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

void sort_012_BruteForce(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
}
void sort_012_Better(vector<int> &nums)
{
    int n = nums.size();
    vector<int> count(3);
    // int count[3];
    for (int i = 0; i < n; i++)
    {
        count[nums[i]]++;
    }
    for (int i = 0; i < count[0]; i++)
    {
        nums[i] = 0;
    }
    for (int i = count[0]; i < count[0] + count[1]; i++)
    {
        nums[i] = 1;
    }
    for (int i = count[0] + count[1]; i < n; i++)
    {
        nums[i] = 2;
    }
}
void sort_012_Best_Dutch_National_Flag_Algorithm(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[mid], nums[low]);
            mid++;
            low++;
        }
        else if (nums[mid] == 1)
        {
            // swap(nums[mid],nums[low]);
            mid++;
            // low++;
        }
        else if (nums[mid] == 2)
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
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
    sort_012_Best_Dutch_National_Flag_Algorithm(array);
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
}
// 8
// 2 2 0 1 2 1 0 1
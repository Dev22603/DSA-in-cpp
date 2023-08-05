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

void Left_Rotate_k(vector<ll> &arr, ll k)
{
    int n = arr.size();
    k = k % n;
    if (!k)
        return;
    vll temp(k);
    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[i];
    }
    for (int i = 0; i < n - k; i++)
    {
        arr[i] = arr[i + k];
    }
    for (int i = n - k; i < n; i++)
    {
        arr[i] = temp[i - (n - k)];
    }
}
void Right_Rotate_k(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;
    if (!k)
        return;
    vector<int> temp(k);
    for (int i = n - k; i < n; i++)
    {
        temp[i - (n - k)] = nums[i];
    }
    for (int i = n - 1; i >= n - k - 1; i--)
    {
        nums[i] = nums[i - k];
    }
    for (int i = 0; i < k; i++)
    {
        nums[i] = temp[i];
    }
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
    Right_Rotate_k(array, d);
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
}
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
void PushZerosToEnd_BruteForce(vector<ll> &arr)
{

    int n = arr.size();
    vll temp;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            temp.push_back(arr[i]);
        }
    }
    for (int i = 0; i < temp.size(); i++)
    {
        arr[i] = temp[i];
    }
    for (int i = temp.size(); i < n; i++)
    {
        arr[i] = 0;
    }
}
void PushZerosToEnd_Better(vector<ll> &arr)
{
    int n = arr.size();
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }
    if (j == -1)
    {
        return;
    }

    for (int i = j + 1; i < n; i++)
    {
        if(arr[i]!=0)
        {
            swap(arr[i],arr[j]);
            j++;
        }
    }
}
int main()
{
    int n, d;
    cin >> n;
    vector<ll> array(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    PushZerosToEnd_Better(array);
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
}
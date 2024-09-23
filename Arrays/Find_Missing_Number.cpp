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
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)


int missingNumber(vector<int>& arr,int N)
{
    int n=arr.size();
    ll a=0;
    for (int i = 0; i < n; i++)
    {
        a+=arr[i];
    }
    return ((N*(N+1))/2-a);
        
}
int missingNumber_Optimal(vector<int>& arr,int N)
{
    // int n=arr.size();
    int xor1=0,xor2=0;
    for (int i = 0; i < N-1; i++)
    {
        xor1^=arr[i];
    }
    for (int i = 1; i <= N; i++)
    {
        xor2^=i;
    }
    return xor1^xor2;
        
}
int main()
{
    int n;
    cin >> n;
    vector<int> array(n);
    for (ll i = 0; i < n-1; i++)
    {
        cin >> array[i];
    }
    cout<<missingNumber(array,n)<<endl;
    cout<<missingNumber(array,n)<<endl;
    
}
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
#define setbit(x,k) (x |=(1LL<<k))
#define usetbit(x,k) (x &= ~(1LL<<k))
#define checkbit(x,k) (x & (1LL<<k))
#define togglebit(x,k) (x ^ (1LL<<k))
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
ll factorial(ll n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return ((n * factorial(n - 1)));
}
ll fastprime(ll a)
{
    if (a != 2 && a % 2 == 0 || a < 2)
        return 0;
    for (ll i = 3; i * i <= a; i += 2)
        if (a % i == 0)
            return 0;
    return 1;
}
int binary_search(vector<int> vec, int querry)
{
    int low, mid, high;
    low = 0, high = vec.size() - 1;
    cout<<high<<"high"<<endl;
    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (vec[mid] == querry)
        {
            return mid;
        }
        else if (vec[low] == querry)
        {
            return low;
        }
        else if (vec[high] == querry)
        {
            return high;
        }
        else if (vec[mid] < querry)
        {
            low = mid + 1;
            high--;
        }
        else if (querry < vec[mid])
        {
            high = mid - 1;
            low++;
        }
    }
    return -1;
}
vector<pair<int, int>> prime_factorisation(ll n)
{
    vector<pair<int, int>> primes;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n /= i;
            }
            primes.push_back({i, cnt});
        }
    }
    if (n > 1)
        primes.push_back({n, 1});
    return primes;
}
void SelectionSort(vector<int> &arr)
{
    int n=arr.size();
    for(int i=0;i<n-1;i++)
    {
        int minimum_index=i;
        for (int j = i; j < n; j++)
        {
            if(arr[minimum_index]>arr[j])
            {
                minimum_index=j;
            }
        }
        swap(arr[minimum_index],arr[i]);
    }
    
}
int main()
{
    int n;
    cin>>n;
    vector<int> array(n);
    for (int i = 0; i < n; i++)
    {
        cin>>array[i];
    }
    cout<<"Before Sorting"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<"After Sorting"<<endl;

    SelectionSort(array);
    for (int i = 0; i < n; i++)
    {
        cout<<array[i]<<" ";
    }

    
}
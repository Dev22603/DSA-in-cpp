
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
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
bool comp(Job a, Job b)
{
    return a.profit>b.profit;
}
vector<int> JobScheduling(Job arr[], int n)
{
    sort(arr,arr+n,comp);
    int max_deadline=0;
    for(int i=0;i<n;i++)
    {
        max_deadline=max(max_deadline,arr->dead);
    }
    vector<int> a(max_deadline+1,-1);
    int count_jobs=0,max_profit=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = arr->dead; j > 0; j--)
        {
            a[j]=arr->id;
            count_jobs++;
            max_profit+=arr->profit;
            break;
        }
    }
    return {count_jobs,max_profit};
    
}

int main()
{
    return 0;
}

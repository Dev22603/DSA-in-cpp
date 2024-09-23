
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


int Minimum_Platforms(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    sort(start.begin(),start.end());
    sort(end.begin(),end.end());
    // for (int i = 0; i < n; i++)
    // {
    //      cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second<<endl;
    // }
    
    int answer=1,platforms=1;
    int s=1,e=0;
    while (s<n && e<n)
    {
        if(start[s]<= end[e])
        {
            platforms++;
            s++;
            answer=max(answer,platforms);
        }
        else if(start[s]>end[e])
        {
            answer=max(answer,platforms);
            platforms--;
            e++;
        }
    }
    
    return answer;
    
}

int main()
{
    int n;
    cin >> n;
    vector<int> start(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> start[i];
    }
    vector<int> end(n);
}

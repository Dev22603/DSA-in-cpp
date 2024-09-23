
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

bool comparator(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    // Agar swap karna hai toh false return karo
    if(a.first.second<b.first.second) return true;
    else if(a.first.second>b.first.second) return false;
    else if (a.second>b.second) return false;
    return true;
}
int N_meetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    vector<pair<pair<int, int>, int>> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[i]={{start[i],end[i]},i+1};
    }
    sort(ans.begin(),ans.end(),comparator);
    for (int i = 0; i < n; i++)
    {
        // cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second<<endl;
    }
    
    int answer=1;
    int last=ans[0].first.second;
    vector<int>meetings={ans[0].second};
    for (int i = 1; i < n; i++)
    {
        if(ans[i].first.first>last)
        {
            answer++;
        // cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second<<endl;
            meetings.push_back(ans[i].second);
            last=ans[i].first.second;
        }
        else if(ans[i].first.first<=ans[i-1].first.second)
        {
            meetings.push_back(ans[i].second);
    
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
    for (ll i = 0; i < n; i++)
    {
        cin >> end[i];
    }
    cout<<N_meetings(start, end);
}

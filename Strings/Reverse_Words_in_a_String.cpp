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

string reverseWords(string s)
{
    string temp = "", str = "";
    vector<string> ans;

    for (int i = 0; i < s.length(); i++)
    {
        while (s[i] != ' ' && i < s.length())
        {
            temp += s[i];
            i++;
        }

        if (temp.length() != 0)
        {
            ans.push_back(temp);
            temp = "";
        }
    }

    for (int j = ans.size() - 1; j >= 0; j--)
    {
        str += ans[j];
        if (j != 0)
        {
            str += " ";
        }
    }
    ans.clear();
    return str;
}
int main()
{
    string s;
    cin >> s;
    string ans = reverseWords(s);
    cout << ans;
}
// nums = [2,7,11,15], target = 9
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


void Merge_Sorted_Arrays_Optimal_1(vector<int> &nums1, int n, vector<int> &nums2, int m)
{
    int left = n - 1;
    int right = 0;
    while (left >= 0 && right < m)
    {
        if (nums1[left] > nums2[right])
        {
            swap(nums1[left], nums2[right]);
            left--;
            right++;
        }
        else
        {
            break;
        }
    }
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
}
void Merge_Sorted_Arrays_Optimal_2_Gap_Method(vector<int> &nums1, int n, vector<int> &nums2, int m)
{
    int len = n + m;
    int gap = len / 2 + len % 2;
    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;
        while (right < len)
        {
            if (left < n && right >= n)
            {
                // nums1 and nums2
                if (nums1[left] > nums2[right - n])
                {
                    swap(nums1[left], nums2[right - n]);
                }
            }
            else if (left >= n)
            {
                // nums2 and nums2
                if (nums2[left - n] > nums2[right - n])
                {
                    swap(nums2[left - n], nums2[right - n]);
                }
            }
            else if (right < n)
            {
                // nums1 and nums1
                if (nums1[left] > nums1[right])
                {
                    swap(nums1[left], nums1[right]);
                }
            }
            left++;
            right++;
        }
        if(gap==1) break;
        gap = gap / 2 + gap % 2;
    }
    // LC
    // for(int i=n;i<len;i++)
    // {
    //     nums1[i]=nums2[i-n];
    // }
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
}

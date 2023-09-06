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

double findMedianSortedArrays_BruteForce(vector<int> &nums1, vector<int> &nums2)
{
    // Brute Force
    int n = nums1.size(), m = nums2.size();
    vector<int> array;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (nums1[i] <= nums2[j])
        {
            array.push_back(nums1[i++]);
        }
        else
        {
            array.push_back(nums2[j++]);
        }
    }
    while (i < n)
    {
        array.push_back(nums1[i++]);
    }
    while (j < m)
    {
        array.push_back(nums2[j++]);
    }
    if ((n + m) % 2)
    {
        return array[(n + m) / 2];
    }
    return ((double)(array[(n + m) / 2] + array[(n + m) / 2 - 1])) / 2;
}
double findMedianSortedArrays_Better(vector<int> &nums1, vector<int> &nums2)
{
    // Better
    int n1 = nums1.size(), n2 = nums2.size();
    int n = n1 + n2;
    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int cnt = 0;
    int ind1el = -1, ind2el = -1;

    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (nums1[i] < nums2[j])
        {
            if (cnt == ind1)
                ind1el = nums1[i];
            if (cnt == ind2)
                ind2el = nums1[i];
            cnt++;
            i++;
        }
        else
        {
            if (cnt == ind1)
                ind1el = nums2[j];
            if (cnt == ind2)
                ind2el = nums2[j];
            cnt++;
            j++;
        }
    }

    // copy the left-out elements:
    while (i < n1)
    {
        if (cnt == ind1)
            ind1el = nums1[i];
        if (cnt == ind2)
            ind2el = nums1[i];
        cnt++;
        i++;
    }
    while (j < n2)
    {
        if (cnt == ind1)
            ind1el = nums2[j];
        if (cnt == ind2)
            ind2el = nums2[j];
        cnt++;
        j++;
    }

    // Find the median:
    if (n % 2 == 1)
    {
        return (double)ind2el;
    }

    return (double)((double)(ind1el + ind2el)) / 2.0;
}

double findMedianSortedArrays_Optimal(vector<int> &nums1, vector<int> &nums2)
{ // Optimal
    int n1 = nums1.size();
    int n2 = nums2.size();
    if (n1 > n2)
        return findMedianSortedArrays_Optimal(nums2, nums1);
    int low = 0, high = n1;
    int n = n1 + n2;
    int left = (n + 1) / 2;
    while (low <= high)
    {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n1)
            r1 = nums1[mid1];
        if (mid2 < n2)
            r2 = nums2[mid2];
        if (mid1 - 1 >= 0)
            l1 = nums1[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = nums2[mid2 - 1];
        if (l1 <= r2 && l2 <= r1)
        {
            if (n % 2)
            {
                return max(l1, l2);
            }
            return ((double)(max(l1, l2) + min(r1, r2))) / 2;
        }
        else if (l1 > r2)
        {
            high = mid1 - 1;
        }
        else
        {
            low = mid1 + 1;
        }
    }
    return 0;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
}
// nums = [2,7,11,15], target = 9
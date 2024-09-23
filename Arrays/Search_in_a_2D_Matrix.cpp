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

// Brute Force will be O(N*M)
int Search_2D_Matrix_Optimized(vector<vector<int>> &matrix, int target)
{
    int r = matrix.size();
    int c = matrix[0].size();
    int low = 0;
    int high = r * c - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (matrix[mid / c][mid % c] == target)
        {
            return 1;
        }
        else if (matrix[mid / c][mid % c] > target)
        {
            high = mid - 1;
        }
        else if (matrix[mid / c][mid % c] < target)
        {
            low = mid + 1;
        }
    }
    return 0;
}
int Search_2D_Matrix_Optimized_By_Dev(vector<vector<int>> &matrix, int target)
{

    int l1 = 0, l2 = 0;
    int row = matrix.size();
    int column = matrix[0].size();
    int h1 = row - 1;
    int h2 = column - 1;
    while (l1 <= h1)
    {
        int m1 = (h1 + l1) / 2;

        if (matrix[m1][h2] < target)
        {
            l1 = m1 + 1;
        }
        else if (matrix[m1][l2] > target)
        {
            h1 = m1 - 1;
        }
        else
        {
            while (l2 <= h2)
            {
                int m2 = (h2 + l2) / 2;
                if (matrix[m1][m2] == target)
                {
                    return 1;
                }
                else if (matrix[m1][m2] > target)
                {
                    h2 = m2 - 1;
                }
                else if (matrix[m1][m2] < target)
                {
                    l2 = m2 + 1;
                }
            }
            return 0;
        }
    }
    return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

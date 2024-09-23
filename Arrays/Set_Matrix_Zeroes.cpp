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

void setZeroes_SELF(vector<vector<int>> &matrix)
{
    int r = matrix.size();
    int c = matrix[0].size();
    vector<int> a;
    vector<int> b;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (matrix[i][j] == 0)
            {
                a.push_back(i);
                b.push_back(j);
            }
        }
    }
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < c; j++)
        {
            matrix[a[i]][j] = 0;
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            matrix[i][b[j]] = 0;
            cout << i << " " << b[j] << endl;
        }
    }
}
void setZeroes_BruteForce_BinaryMatrix(vector<vector<int>> &matrix)
{
    int r = matrix.size();
    int c = matrix[0].size();
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (matrix[i][j] == 0)
            {
                // set all elements in row to -1
                for (int k = 0; k < c; k++)
                {
                    if (matrix[i][k] != 0)
                        matrix[i][k] = -1;
                }
                // set all elements in column to -1
                for (int k = 0; k < r; k++)
                {
                    if (matrix[k][j] != 0)
                        matrix[k][j] = -1;
                }
            }
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}
void setZeroes_Better(vector<vector<int>> &matrix)
{
    int r = matrix.size();
    int c = matrix[0].size();
    vector<int> row(r);
    vector<int> col(c);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (matrix[i][j] == 0)
            {
                // set all elements in row to -1
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (row[i] == 1 || col[j] == 1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}
void setZeroes_Optimal(vector<vector<int>> &matrix)
{
    int r = matrix.size();
    int c = matrix[0].size();
    int col0 = matrix[0][0];

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (matrix[i][j] == 0)
            {
                if (j == 0)
                {
                    col0 = 0;
                    matrix[i][0] = 0;
                }
                else
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
    }
    for (int i = 1; i < r; i++)
    {
        for (int j = 1; j < c; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < c; j++)
        {
            {
                matrix[0][j] = 0;
            }
        }
    }
    if (col0 == 0)
    {
        for (int j = 0; j < r; j++)
        {
            {
                matrix[j][0] = 0;
            }
        }
    }
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
    setZeroes_Optimal(matrix);
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
// 3
// 4
// 0 1 2 0
// 3 4 5 2
// 1 3 1 5
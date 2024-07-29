#include <bits/stdc++.h>
using namespace std;

void subset_sum(int i, int n, int s, vector<int> &nums, vector<int> &ans)
{
    if (i == n)
    {
        ans.push_back(s);
        return;
    }
    subset_sum(i + 1, n, s + nums[i], nums, ans);
    subset_sum(i + 1, n, s, nums, ans);
}
vector<int> subsets(vector<int> &nums)
{
    vector<int> a;
    int s = 0;
    int n = nums.size();
    subset_sum(0, n, s, nums, a);

    return a;
}
int main()
{
    int n;
    cin >> n;
    vector<int> array(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
}

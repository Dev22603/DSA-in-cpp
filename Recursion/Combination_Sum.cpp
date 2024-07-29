#include <bits/stdc++.h>
using namespace std;


void Combination_Optimal(int i, int n, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &temp)
{
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }
    if (i == n)
    {
        return;
    }
    if (arr[i] <= target)
    {
        temp.push_back(arr[i]);
        Combination(i, n, target - arr[i], arr, ans, temp);
        temp.pop_back();
    }
    Combination(i + 1, n, target, arr, ans, temp);
}
void Combination(int i, int n, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &temp)
{
    if (i == n)
    {
        if (target == 0)
        {
            ans.push_back(temp);
        }
        return;
    }
    if (arr[i] <= target)
    {
        temp.push_back(arr[i]);
        Combination(i, n, target - arr[i], arr, ans, temp);
        temp.pop_back();
    }
    Combination(i + 1, n, target, arr, ans, temp);
}

vector<vector<int>> combinationSum(vector<int> &arr, int k)
{

    vector<vector<int>> ans;
    vector<int> temp;
    int n = arr.size();
    Combination(0, n, k, arr, ans, temp);
    return ans;
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


#include <bits/stdc++.h>
using namespace std;
int calcWaitTime(vector<int> &priority, int position)
{
    int in = -1;
    int maxi = -1;
    int n = priority.size();
    for (int i = 0; i < n; i++)
    {
        if (maxi < priority[i])
        {
            in = i;
            maxi = priority[i];
        }
    }
    if (in == position)
        return 0;
    priority[in] = -1;

    for (int i = 0; i < in; i++)
    {
        if (priority[i] > 0)
            priority[i]++;
    }

    return 1 + calcWaitTime(priority, position);
}
int main()
{
    int t, n;
    cin >> n;
    vector<int> array(n);
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    int k;
    cin >> k;
    k--;
    cout << 1 + calcWaitTime(array, k) << endl;
    return 0;
}

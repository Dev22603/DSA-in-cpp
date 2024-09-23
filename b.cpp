
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string goodString, name;
    getline(cin, goodString);
    getline(cin, name);
    int placementlelo = 0;
    vector<int> a;
    for (auto i : goodString)
    {
        a.push_back((int)i);
    }
    sort(a.begin(), a.end());
    int totalDistance = 0;
    int prev_good_char = (int)goodString[0];
    for (auto i : name)
    {
        int b = (int)i;
        int l = 0, r = a.size() - 1;
        int minDistance = INT_MAX;
        int curr = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (a[mid] == b)
            {
                curr = prev_good_char;
                minDistance = 0;
                break;
            }
            else if (a[mid] < b)
            {
                if (abs(a[mid] - b) < minDistance)
                {
                    minDistance = abs(a[mid] - b);
                    curr = a[mid];
                }
                else if (abs(a[mid] - b) == minDistance)
                {
                    if (abs(curr - prev_good_char) > abs(a[mid] - prev_good_char))
                    {
                        curr = a[mid];
                        minDistance = abs(a[mid] - prev_good_char);
                    }
                    else
                    {
                        minDistance = abs(curr - prev_good_char);
                    }
                }
                l = mid + 1;
            }
            else
            {
                if (abs(a[mid] - b) < minDistance)
                {
                    minDistance = abs(a[mid] - b);
                    curr = a[mid];
                }
                else if (abs(a[mid] - b) == minDistance)
                {
                    if (abs(curr - prev_good_char) > abs(a[mid] - prev_good_char))
                    {
                        curr = a[mid];
                        minDistance = abs(a[mid] - prev_good_char);
                    }
                    else
                    {
                        minDistance = abs(curr - prev_good_char);
                    }
                }
                r = mid - 1;
            }
        }
        prev_good_char = curr;
        totalDistance += minDistance;
    }
    cout << totalDistance;
}

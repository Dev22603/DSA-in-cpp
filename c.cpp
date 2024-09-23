#include <bits/stdc++.h>
using namespace std;

int combination(char arr[], int n)
{
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        string s(1, arr[i]);
        for (int j = i + 1; j < n; j++)
        {
            s += arr[j];
            if (s[0] != arr[j])
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (s[1] != arr[k])
                    {
                        ans++;
                    }
                }
            }
            s = string(1, arr[i]);
        }
    }
    return ans;
}

int main()
{
    string ashok, anand;
    getline(cin, ashok);
    getline(cin, anand);

    char as[ashok.size() + 1];
    char an[anand.size() + 1];
    strcpy(as, ashok.c_str());
    strcpy(an, anand.c_str());

    int placementlelo_as = combination(as, ashok.size());
    int placementlelo_an = combination(an, anand.size());

    if (placementlelo_as == 0 && placementlelo_an == 0)
    {
        cout << "Invalid input";
    }
    else if (placementlelo_as > placementlelo_an)
    {
        cout << "Ashok";
    }
    else if (placementlelo_an > placementlelo_as)
    {
        cout << "Anand";
    }
    else
    {
        cout << "Draw";
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{

    long long L, K;
    cin >> L >> K;
    if (K == 0)
    {
        cout << L;
        return 0;
    }
    long long lengthOfZeores = L - K;
    K++;
    long long ans = lengthOfZeores / K;
    if (lengthOfZeores % K != 0)
    {
        ans++;
    }

    cout << ans;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int Bubblesort(vector<int> arr)
{
    int n = arr.size();
    int numberOfSwaps = 0;
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0)
        {
            if (arr[j] < arr[j - 1])
            {

                swap(arr[j], arr[j - 1]);
                numberOfSwaps++;
            }
            j--;
        }
    }
    return numberOfSwaps;
}
int BubblesortDesc(vector<int> arr)
{
    int n = arr.size();
    int numberOfSwaps = 0;
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0)
        {
            if (arr[j] > arr[j - 1])
            {

                swap(arr[j], arr[j - 1]);
                numberOfSwaps++;
            }
            j--;
        }
    }
    return numberOfSwaps;
}

int main()
{
    int n;
    cin >> n;
    vector<int> array(n);
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    int swapsRequiredAscending = Bubblesort(array);
    int swapsRequiredDescending = BubblesortDesc(array);
    cout << min(swapsRequiredDescending, swapsRequiredAscending);
}

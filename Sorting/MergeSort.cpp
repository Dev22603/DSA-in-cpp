#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void Merge(vector<int> &arr, int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    vector<int> temp;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left++]);
        }
        else
        {
            temp.push_back(arr[right++]);
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left++]);
    }
    while (right <= high)
    {
        temp.push_back(arr[right++]);
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}
void MergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    MergeSort(arr, low, mid);
    MergeSort(arr, mid + 1, high);
    Merge(arr, low, mid, high);
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
    cout << "Before Sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    cout << "\nAfter Sorting" << endl;
    MergeSort(array, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
}

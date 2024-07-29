
#include <bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comp(Job a, Job b)
    {
        return a.profit>b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n)
{
    sort(arr,arr+n,comp);
    int max_deadline=arr[0].dead;
    for(int i=1;i<n;i++)
    {
        max_deadline=max(max_deadline,arr[i].dead);
    }
    vector<int> a(max_deadline,-1);
    int count_jobs=0,max_profit=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead; j > 0; j--)
        {
            if(a[j-1]==-1)
            {
                
            a[j-1]=arr[i].id;
            count_jobs++;
            max_profit+=arr[i].profit;
            break;
            }
        }
    }
    return {count_jobs,max_profit};
    
} 
};

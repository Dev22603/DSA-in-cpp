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

// Definition for singly-linked list.
class ListNode
{

public:
    int data;
    ListNode *next;

    // constructor
    ListNode()
    {
        this->next = NULL;
    }
};
// Constructor modified for this question
ListNode *Remove_Brute(ListNode *&Head, int n)
{
    int len=0;
    ListNode *temp = Head;
    while (temp)
    {
        len++;
        temp = temp->next;
    }
    if(n==len)
    {
        return Head->next;
    }
    temp = Head;
    n=len-n;
    for (int i =1; i < n; i++)
    {
        temp = temp->next;
    }
    temp->next = temp->next->next;
    return Head;
}
ListNode *Remove_Optimal_Hare_Tortoise(ListNode *&Head,int n)
{
    ListNode *start= new ListNode();
    start->next=Head;
    ListNode *slow = start;
    ListNode *fast = start;
    for (int i = 1; i <= n; i++)
    {
        fast=fast->next;
    }
    while (fast->next)
    {
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=slow->next->next;
    return start->next;
    
    
    return slow;
}

int main()
{
}
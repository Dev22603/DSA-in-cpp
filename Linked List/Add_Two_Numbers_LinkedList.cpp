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
    int val;
    ListNode *next;

    // constructor
    ListNode()
    {
        this->next = NULL;
    }
};
// Constructor modified for this question and val 
ListNode *addTwoNumbers_Optimal(ListNode *l1, ListNode *l2)
{
    ListNode *start = new ListNode();
    ListNode *NewHead=start;
    start->val= 0;
    int sum = 0, carry = 0;
    while (l1 && l2)
    {
        sum=(l1->val+l2->val+carry)%10;
        carry=(l1->val+l2->val+carry)/10;
        ListNode *temp=new ListNode();
        temp->val=sum;
        start->next=temp;
        start=start->next;
        l1=l1->next;
        l2=l2->next;
    }
    while(l1)
    {
        sum=(l1->val+carry)%10;
        carry=(l1->val+carry)/10;
        ListNode *temp=new ListNode();
        temp->val=sum;
        start->next=temp;
        start=start->next;
        l1=l1->next;

    }
    while(l2)
    {
        sum=(l2->val+carry)%10;
        carry=(l2->val+carry)/10;
        ListNode *temp=new ListNode();
        temp->val=sum;
        start->next=temp;
        start=start->next;
        l2=l2->next;
    }
    if(carry)
    {
        ListNode *temp=new ListNode();
        temp->val=carry;
        start->next=temp;
        start=start->next;

    }
    return NewHead->next;
}

int main()
{
}
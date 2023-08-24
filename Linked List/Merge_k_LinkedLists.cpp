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
    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
ListNode *mergelist(ListNode *list1, ListNode *list2)
{
    if (list1 == NULL && list2 == NULL)
    {
        return NULL;
    }
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }

    if (list1->val > list2->val)
    {
        swap(list1, list2);
    }
    ListNode *res = list1;

    while (list1 && list2)
    {

        ListNode *temp = NULL;
        while (list1 && list1->val <= list2->val)
        {
            temp = list1;
            list1 = list1->next;
        }
        temp->next = list2;
        swap(list1, list2);
    }
    return res;
}
void Delete(ListNode *l1)
{
    if (l1->next->next == NULL)
    {
        l1->next = NULL;
    }
    l1->val = l1->next->val;
    l1->next = l1->next->next;
}
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
        return NULL;
    ListNode *head = new ListNode(0);
    head = lists[0];

    int n = lists.size();

    for (int i = 1; i < n; i++)
    {
        head = mergelist(head, lists[i]);
    }
    // return head;
    // ListNode* HEAD=head;
    // while(HEAD && HEAD->next)
    // {
    //     if(HEAD->val==HEAD->next->val)
    //     {
    //         Delete(HEAD);
    //     }
    //     HEAD=HEAD->next;
    // } for unique nodes
    return head;
}
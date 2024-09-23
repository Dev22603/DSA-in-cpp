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
    ListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

ListNode *mergeTwoLists_External_Space(ListNode *list1, ListNode *list2)
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

    ListNode *ans = NULL;
    ListNode *ret = NULL;
    ListNode *h1 = list1;
    ListNode *h2 = list2;
    while (h1 != NULL && h2 != NULL)
    {
        if (h1->data > h2->data)
        {
            if (ans == NULL)
            {
                ans = h2;
                ret = ans;
                h2 = h2->next;
            }
            else
            {
                ans->next = h2;
                ans = ans->next;
                h2 = h2->next;
            }
        }
        else
        {
            if (ans == NULL)
            {
                ans = h1;
                ret = ans;
                h1 = h1->next;
            }
            else
            {
                ans->next = h1;
                ans = ans->next;
                h1 = h1->next;
            }
        }
    }

    while (h1 != NULL)
    {
        ans->next = h1;
        ans = ans->next;
        h1 = h1->next;
    }
    while (h2 != NULL)
    {
        ans->next = h2;
        ans = ans->next;
        h2 = h2->next;
    }

    return ret;
}
ListNode *mergeTwoLists_In_Place(ListNode *list1, ListNode *list2)
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

    if (list1->data > list2->data)
    {
        swap(list1, list2);
    }
    ListNode *res = list1;

    while (list1 && list2)
    {

        ListNode *temp = NULL;
        while (list1 && list1->data <= list2->data)
        {
            temp = list1;
            list1 = list1->next;
        }
        temp->next = list2;
        swap(list1, list2);
    }
    return res;
}

int main()
{
}
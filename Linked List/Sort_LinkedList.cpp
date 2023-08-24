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

ListNode *sortList(ListNode *head)
{
    // If List Contain a Single or 0 Node
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *temp = NULL;
    ListNode *slow = head;
    ListNode *fast = head;

    // 2 pointer appraoach / turtle-hare Algorithm (Finding the middle element)
    while (fast != NULL && fast->next != NULL)
    {
        temp = slow;
        slow = slow->next;       // slow increment by 1
        fast = fast->next->next; // fast incremented by 2
    }
    temp->next = NULL; // end of first left half

    ListNode *l1 = sortList(head); // left half recursive call
    ListNode *l2 = sortList(slow); // right half recursive call

    return mergelist(l1, l2); // mergelist Function call
}

// MergeSort Function O(n*logn)
ListNode *mergelist(ListNode *l1, ListNode *l2)
{
    ListNode *ptr = new ListNode(0);
    ListNode *curr = ptr;

    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val <= l2->val)
        {
            curr->next = l1;
            l1 = l1->next;
        }
        else
        {
            curr->next = l2;
            l2 = l2->next;
        }

        curr = curr->next;
    }
    // for unqual length linked list
    if (l1 != NULL)
    {
        curr->next = l1;
        l1 = l1->next;
    }
    if (l2 != NULL)
    {
        curr->next = l2;
        l2 = l2->next;
    }
    return ptr->next;
}
int main()
{
}
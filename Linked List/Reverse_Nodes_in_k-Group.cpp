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

// utility function to insert ListNode in the list
void insertNode(ListNode *&head, int data)
{
    ListNode *newNode = new ListNode(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    ListNode *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return;
}
// utility function to find length of the list
int lengthOfLinkedList(ListNode *head)
{
    int length = 0;
    while (head != NULL)
    {
        ++length;
        head = head->next;
    }
    return length;
}
// utility function to reverse k nodes in the list
ListNode *reverseKGroup(ListNode *&head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;

    int length = lengthOfLinkedList(head);

    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = head;

    ListNode *pre = dummyHead;
    ListNode *cur;
    ListNode *nex;

    while (length >= k)
    {
        cur = pre->next;
        nex = cur->next;
        for (int i = 1; i < k; i++)
        {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        length -= k;
    }
    return dummyHead->next;
}
// utility function to print the list
void printLinkedList(ListNode *&head)
{
    while (head->next != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << head->data << "\n";
}

int main()
{
    ListNode *head = NULL;
    int k = 3;
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);
    insertNode(head, 6);
    insertNode(head, 7);
    insertNode(head, 8);

    cout << "Original Linked List: ";
    printLinkedList(head);
    cout << "After Reversal of k nodes: ";
    ListNode *newHead = reverseKGroup(head, k);
    printLinkedList(newHead);

    return 0;
}
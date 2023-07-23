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

ListNode *middle_Brute(ListNode *&Head)
{
    int n = 0;
    ListNode *temp = Head;
    while (temp)
    {
        n++;
        temp = temp->next;
    }
    n = n / 2;
    temp=Head;
    for (int i = 0; i < n; i++)
    {
        temp = temp->next;
    }
    return temp;
}
ListNode *middle_Optimal_Hare_Tortoise(ListNode *&Head)
{
 ListNode *slow=Head;
    ListNode *fast=Head;
    while (fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
    
}

int main()
{
}
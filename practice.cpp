#include<bits/stdc++.h>
using namespace std;

int main()
{
    class Node
    {
    public:
        int val;
        Node* next;
    };
    Node* head;
    Node* one = NULL;
    Node* two = NULL;

    one = new Node();
    two = new Node();

    one->val = 1;
    two->val = 2;
    one->next = two;
    two->next = NULL;
    head = one;
    while(head != NULL)
    {
        cout<<head-> val;
        head = head->next;
    }

}

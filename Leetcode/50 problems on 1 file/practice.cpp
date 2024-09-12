#include<bits/stdc++.h>
using namespace std;

int main(){

    queue<int> qu;
    qu.push(1);
    qu.push(2);
    qu.push(3);

    cout << qu.front();
    cout << qu.back();
    cout << "\n";

    while(!qu.empty()){
        cout << qu.front();
        qu.pop();
    }

}


/*#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int> myStack;

    myStack.push(1);
    myStack.push(2);

    cout << myStack.top();

    while(!myStack.empty()){
    cout << myStack.top();
    myStack.pop();
    }
}


//linked list
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

}*/

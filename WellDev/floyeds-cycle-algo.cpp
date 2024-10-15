#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;


};

bool hasCycle(ListNode* head){
    if(!head)return false;

    ListNode* slow;
    ListNode* fast;

    while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

        if(fast == slow) return true;
        else return false;
    }
}

int main(){

}

#include<bits/stdc++.h>
using namespace std;


struct ListNode{
    int val;
    ListNode* next;
};


ListNode* reverseLinLis(ListNode* head){

    ListNode* temp2;
    ListNode* temp = NULL;

    while(!head.empty()){
        temp2 = head->next;
        head->next = temp;
        temp= head;
        head = temp2;
    }
}

int main(){

}

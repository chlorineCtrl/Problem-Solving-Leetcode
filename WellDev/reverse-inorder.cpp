#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};



void reInorder(TreeNode* root){
    //base case
    if(root.empty()){
        return;
    }


    //recursive solution
    reInorder(root->right);
    cout << root->val << " ";
    reInorder(root->left);
}




int main(){

}

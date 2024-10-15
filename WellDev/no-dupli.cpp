#include<bits/stdc++.h>
using namespace std;

int main(){

    int arr[5] = {1,3,4,4,1};
    unordered_set<int>  myset;
    int i = sizeof(arr)/sizeof(arr[0])-1;
    while(i>= 0){
            myset.insert(arr[i]);
            i--;
    }
    for(auto it = myset.begin(); it != myset.end(); it++){
        cout << *it;
    }


}

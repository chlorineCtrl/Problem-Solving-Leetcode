
#include<bits/stdc++.h>
using namespace std;

void nonZeroMover(vector<int>& arr, int n){
    int j  = 0;

    for(int i = 0; i <n ; i++){
        if(arr[i] != 0){
            arr[j] = arr[i];
            j++;
        }
    }

    while(j<n){
        arr[j] = 0;
        j++;
    }
}

int main(){
    vector<int> arr = {2,1,0,0,2,0,3,0};
    int n = arr.size();

    nonZeroMover(arr, n);

    for(auto i:arr){
        cout << i << " ";
    }
}

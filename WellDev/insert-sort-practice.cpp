#include<bits/stdc++.h>
using namespace std;

void insertSort(vector<int>& arr, int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i-1;

        while(arr[j] > key && j >= 0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}


int main(){
    vector<int> arr ={24,12,23,2,1};
    int n = arr.size();

    insertSort(arr,n);

    for(auto i:arr){
        cout << i << " ";
    }
}

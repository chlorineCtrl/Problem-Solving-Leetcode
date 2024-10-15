#include<bits/stdc++.h>
using namespace std;

int partitions(){
        // this function return the sorted pivot position
}

void quickSort(vector<int>& arr, int low, int high){
        if(low < high){
            int part = partitions(arr,low, high);

            quickSort(arr, low, part-1);
            quickSort(arr,part+1, high);
        }
}

int main(){
    vector<int> arr = {10,2,12,3,6};
    int n = arr.size();

    quickSort(arr, 0, n-1);
}


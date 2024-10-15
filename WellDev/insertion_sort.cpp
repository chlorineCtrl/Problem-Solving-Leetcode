#include<bits/stdc++.h>
using namespace std;

void insertSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i-1;

        while(j >=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void printArr(int arr[], int n){
    int i = 0;
    while(i < n){
        cout << arr[i] << " ";
        i++;
    }
}

int main(){
    int arr[] = {1,2,12,3,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    insertSort(arr,n);

    printArr(arr,n);
}

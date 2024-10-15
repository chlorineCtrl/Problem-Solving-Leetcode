#include<bits/stdc++.h>
using namespace std;


int main(){

    int arr[] = {3,7,1,9,5};
    sort(arr,arr+5);


    int i=0, j=4;
    int minx = 0, maxn = 0;
    while(i<=3){
        minx += arr[i];
        i++;
    }
    while(j > 0){
        maxn += arr[j];
        j--;
    }

    cout << minx;
    cout << maxn;

}

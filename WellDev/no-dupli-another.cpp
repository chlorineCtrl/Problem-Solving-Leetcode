#include<bits/stdc++.h>
using namespace std;

int main(){

    int arr[5] = {1,3,4,4,1};
    unordered_map<int,int> umap;

    for(auto i: arr){
        umap[i]++;
    }

    for(auto it = umap.begin(); it != umap.end(); ++it){
       if(it->second == 1) cout << it->first;
    }





}

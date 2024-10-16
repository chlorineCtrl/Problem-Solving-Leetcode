#include<bits/stdc++.h>
using namespace std;

int sqrtFinder(int x){
    int left = 0;
    int right = 8;
    int result = 0;
    while(low <= high){
        int mid = left + (right-left)/2;
        long long square =(long long)mid * mid;

        if(square == x) return mid;

        else if(square < x){
            result = mid;
            low = mid + 1;
        }
        else if (square > x){
            result = mid;
            high = mid -1;
        }
    }
    return result;
}


int main(){

}

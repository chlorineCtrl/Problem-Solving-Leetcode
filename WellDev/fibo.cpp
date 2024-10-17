#include<bits/stdc++.h>
using namespace std;

int main(){
    int a = 0;
    int  b = 1;
    cout << a <<" "<<b<<" ";
    for(int i = 2; i <= 5 ; i++){
        b = a+b;
        a = b-a;

        cout << b << " ";
    }


}

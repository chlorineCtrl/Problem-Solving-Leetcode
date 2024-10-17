#include<Bits/stdc++.h>
using namespace std;


class Myclass{
public:
    void myfync(int x){
    cout << x;
    }

    void myfync(float y, int x){
        cout << y << x;
    }

};


int main(){
        Myclass myc;
        myc.myfync(3);
        myc.myfunc(2.44, 5);
}


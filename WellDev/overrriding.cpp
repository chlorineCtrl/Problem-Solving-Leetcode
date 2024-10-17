#include<Bits/stdc++.h>
using namespace std;


class Myclass{
public:
    void myfync(){
    cout << "helloL" ;
    }

};

class Boroclass : public Myclass {
    void myfync(){
    cout << "world";
    }

};


int main(){
        Myclass myc;
        myc.myfync();

}


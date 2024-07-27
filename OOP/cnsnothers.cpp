#include<bits/stdc++.h>
using namespace std;

class Car{
public:
    Car(){
        name = "Vyron";
    }
 string name;
 double speed;

 void maxSpeed(double s){

    cout << speed*s;
}

};

int main(){
    Car bugatti;

    cout << bugatti.name;
    bugatti.maxSpeed(7);
}

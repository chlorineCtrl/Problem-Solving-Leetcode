#include<bits/stdc++.h>
using namespace std;

  class Car{
      public:
        string name;
        double speed;

        void maX(int mult){
            cout << mult * speed;
        }
    };

int main(){
    Car bugatti;
    bugatti.speed = 10.9;
    cout << bugatti.speed<< " ";
    bugatti.maX(3);

}

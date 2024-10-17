#include<bits/stdc++.h>
using namespace std;

class Employee{
public:
    Employee(){};

private:
    int salary;
public:
    void setSalary(int n){
    salary = n;
    }
    int getSalary(){
    return salary;
    }

};


int main(){
    Employee emp;
    emp.setSalary(3242);
    cout << emp.getSalary();

}

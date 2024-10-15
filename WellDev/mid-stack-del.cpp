#include<bits/stdc++.h>
using namespace std;

void midDel(stack<int>& st,int middle){

//base case

if(middle ==  0){
    st.pop();
    return;
}

int top = st.top();
st.pop();

midDel(st, middle-1);

st.push(top);
}

int main(){
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

int middle = st.size()/2;

    midDel(st,middle);


    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
}

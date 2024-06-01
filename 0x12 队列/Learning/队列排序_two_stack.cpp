//
// Created by AaronPang on 6/1/24.
//
#include<iostream>
#include<stack>
using namespace std;
stack <int> a,b;
int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        int x;
        cin>>x;
        a.push(x);
    }
    b.push(a.top());
    a.pop();
    while(!a.empty()){
        if(a.top()>b.top()){
            b.push(a.top());
            a.pop();
        }
        else{
            int temp=a.top();
            a.pop();
            while(  ! b.empty() && temp<b.top()){
                a.push(b.top());
                b.pop();
            }
            b.push(temp);
        }
    }
    while(!b.empty()){
        cout<<b.top()<<' ';
        b.pop();
    }
    return 0;
}
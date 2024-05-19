//
// Created by AaronPang on 5/17/24.
//
#include<iostream>
#include<stack>
using namespace std;
int train_count(stack<int> train,stack<int> number,bool f){
    int count=0;
    if (f){
        if (train.empty()){
            return 0;
        }
        else{
            train.pop();
            if(number.empty() && train.empty()){
                return 1;
            }
            count+= train_count(train,number,true);
            count+= train_count(train,number,false);
            return count;
        }
    }
    else{
        if(number.empty()){
            return 0;
        }
        else{
            train.push(number.top());
            number.pop();
            count+= train_count(train,number,true);
            count+= train_count(train,number,false);
            return count;
        }
    }
}
int main(){
    int n;
    cin>>n;
    stack <int> number,train;
    for (int i=1;i<=n;i++){
        number.push(i);
    }
    int count;
    count=train_count(train,number,false);
    cout<<count<<endl;
    return 0;
}
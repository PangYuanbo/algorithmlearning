//
// Created by AaronPang on 5/17/24.
//
#include<iostream>
using namespace std;
int train(int n){
    int count;
    if (n==1){
        return 1;
    }
    for(int i=1;i<=n;i++){
        count+=train(i-1)*train(n-i);
    }
    return count;

}
int main(){
    int n;
    cin>>n;
    cout<<train(n)<<endl;
    return 0;
}
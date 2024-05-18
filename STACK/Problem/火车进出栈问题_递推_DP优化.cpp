//
// Created by AaronPang on 5/17/24.
//
#include<iostream>
using namespace std;
int number[60001]={0};
int train(int n){
    int count;
    count =0;
    if(number[n]!=0){
        return number[n];
    }
    if (n==1){
        return 1;
    }
    count+=train(n-1);
    for(int i=2;i<n;i++){

        count+=train(i-1)*train(n-i);
    }
    count+= train(n-1);
    number[n]=count;
    return count;

}
int main(){
    int n;
    cin>>n;
    number[1]=1;
    cout<<train(n)<<endl;
    return 0;
}
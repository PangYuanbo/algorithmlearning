//
// Created by 14653 on 5/11/2024.
//

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
void move(char a,char b){
    cout<<a<<"->"<<b<<endl;
}
void hanoi(int n ,char x, char y, char z){
    if(n==1){
        move(x,y);
        return ;
    }
    else{
        hanoi(n-1,x,z,y);
        move(x,y);
        hanoi(n-1,z,y,x);
    }
}
int main(){
    int n;
    cin>>n;
    hanoi(n,'A','C','B');
    return 0;
}
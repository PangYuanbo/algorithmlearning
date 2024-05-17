//
// Created by AaronPang on 5/15/24.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void move(char a, char b){
    cout << a << "->" << b << endl;
}
void hanoi(int n, char s, char d, char m){
    if (n==1){
        move(s,d);
        return ;
    }
    else{
        hanoi(n-1,s,m,d);
        move(s,d);
        hanoi(n-1,m,d,s);
    }
}
int main(){
    int n;
    cin>>n;
    hanoi(n,'A','C','B');
    return 0;
}
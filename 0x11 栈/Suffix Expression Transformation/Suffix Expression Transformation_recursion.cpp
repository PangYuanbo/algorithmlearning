//
// Created by 14653 on 5/19/2024.
//
#include<iostream>
using namespace std;
string s;
int calculate(int l,int r){
    if (s[l]=='(' && s[r]==')'){
        return calculate(l+1,r-1);
    }
    for (int i=r;i>=l;i--){
        if (s[i]=='+' || s[i]=='-'){
            return calculate(l,i-1)+calculate(i+1,r)*(s[i]=='+'?1:-1);
        }
    }
    for (int i=r;i>=l;i--){
        if(s[i]=='*'){
            return calculate(l,i-1)*calculate(i+1,r);
        }
        if(s[i]=='/') {
            return calculate(l, i - 1) / calculate(i + 1, r);
        }
    }
    return s[(l+r)/2]-'0';
}
int main(){
    cin>>s;
    int len = s.size();
    cout<<calculate(0,len-1)<<endl;
    return 0;
}
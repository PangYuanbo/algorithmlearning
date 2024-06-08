//
// Created by AaronPang on 6/8/24.
//
#include<iostream>
#include<cstring>
using namespace  std;
int a[8];
int main(){
    int k;
    cin>>k;
    while (k>0){
        int m,n;
        cin>>m>>n;
        for(int i=1;i<=7;i++){
            a[i]=n;
        }
        string s;
        cin>>s;
        for(int i=0;i<s.length();i++){
            a[int(s[i])-64]--;
        }
        int count=0;
        for(int i=1;i<=7;i++){
            if(a[i]>0){count+=a[i];}
        }
        cout<<count<<endl;
        k--;
    }
    return 0;
}
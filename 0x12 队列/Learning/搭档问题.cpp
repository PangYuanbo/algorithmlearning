//
// Created by AaronPang on 6/1/24.
//
#include <iostream>
using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    char a[n+1],b[m+1];
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    if(n>m){
        int f=m*(k-1)%n+1;
        int p=1;
        for (int i=f;i<=n;i++){
            cout<<a[i]<<' '<<b[p]<<endl;
            p++;
        }
        f=1;
        for(int i=p;i<=m;i++){
            cout<<a[f]<<' '<<b[i]<<endl;
            f++;
        }
    }
    else if(n<m){

    }
    else{
        for (int i=1;i<=n;i++){
            cout<<a[i]<<' '<<b[i]<<endl;
        }
    }
}
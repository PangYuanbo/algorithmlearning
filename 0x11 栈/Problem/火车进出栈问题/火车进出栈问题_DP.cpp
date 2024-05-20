//
// Created by AaronPang on 5/18/24.
//
//f[0][0]=1
//f[i][j]=f[i-1][j]+f[i][j-1]
#include<iostream>
using namespace std;
int f[60001][60001]={0};
int main(){
    int n;
    cin>>n;
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            if (j==0){
                f[i][j]=f[i-1][j];
            }
            else{
                f[i][j]=f[i-1][j]+f[i][j-1];
            }
        }
    }
    cout<<f[n][n]<<endl;
    return 0;
}
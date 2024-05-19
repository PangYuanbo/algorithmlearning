//
// Created by AaronPang on 5/18/24.
//
#include<iostream>
using namespace std;
double value[1000];

int main(){
    int n;
    cin>>n;
    double f[n+1][n+1][n+1];
    for (int i=1;i<=n;i++){
        cin>>value[i];
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++){
                f[i][j][k]=0;
            }
        }
    }
    f[0][0][0]=1;
    for (int i=1;i<=n;i++){
        f[i][0][0]=(1-value[i])*f[i-1][1][0];
        for(int k=1;k<=i;k++){
            f[i][0][k]=(1-value[i])*f[i-1][0][k-1]+(1-value[i])*f[i-1][1][k];
        }
        for (int j=1;j<=i;j++){
            for (int k=0;k<=i;k++){
                f[i][j][k]=value[i]*f[i-1][j-1][k]+(1-value[i])*f[i-1][j+1][k];
            }
        }
    }
    double count=0;
    for (int j=0;j<=n;j++){
        for(int k=0;k<=n-j;k++){
            count+=(n-j-k)*f[n][j][k];
        }
    }
    cout<<count<<endl;

}
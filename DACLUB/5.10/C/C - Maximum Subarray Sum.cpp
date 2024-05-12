//
// Created by 14653 on 5/10/2024.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int max_sum=a[0];
    int sum=a[0];
    for(int i=1;i<n;i++){
        sum=max(a[i],sum+a[i]);
        max_sum=max(max_sum,sum);
    }
    cout<<max_sum;
    return 0;
}
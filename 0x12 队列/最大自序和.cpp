//
// Created by 14653 on 6/2/2024.
//
//
// Created by AaronPang on 6/2/24.
//
///单调队列是一种在队列的基础上，维护一个单调递增或递减的序列的数据结构123。单调队列可以在队首和队尾进行出队操作，但只能在队尾进行入队操作43。在入队时，如果新元素破坏了队列的单调性，就要不断弹出队尾元素，直到恢复单调性435。单调队列可以用来解决一些滑动窗口的问题，例如求窗口内的最大值或最小值35。

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int a[n+1],sum[n+1];
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sum[0]=0;
    for (int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int ans=0;
    int l=1,r=1;
    int count=0;
    for(int i=2;i<=n;i++) {
        r++;
        while (l <= r && i - m > l) {
            l++;
            count++;
        }
        while (l <= r && sum[l]>sum[i]) {
            l++;
            count++;
        }
        ans = max(ans, sum[i] - sum[l ]);
    }
    cout<<ans<<endl;
    return 0;
}
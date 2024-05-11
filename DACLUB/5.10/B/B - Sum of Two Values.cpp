//
// Created by 14653 on 24-5-10.
//
#include<iostream>
#include<algorithm>
#include<array>
#include<vector>
using namespace std;

struct number{
    int value;
    int index;
};

//错误版本的二分查找，由于这道题目需要排除重复的情况，所以不能使用这个二分查找，需要在二分查找中引入下标，从而确定查找的不是同一个元素
//int binary_search(const vector<number>& a,int x,int l,int r){
//    while(l<=r){
//        int mid=(l+r)/2;
//        if(a[mid].value==x){
//            return a[mid].index+1;
//        }
//        else if(a[mid].value<x){
//            l=mid+1;
//        }
//        else{
//            r=mid-1;
//        }
//    }
//    return false;
//}
// 正确实现二分搜索
int binary_search(const vector<number>& a, int x, int l, int r, int exclude_index) {
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid].index != exclude_index) {  // 确保不是同一个元素
            if (a[mid].value == x) {
                return a[mid].index + 1;
            } else if (a[mid].value < x) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        } else {  // 如果是同一元素，跳过
            if (a[mid].value < x) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    return -1;  // 未找到返回 -1
}
bool cmp(const number& a, const number& b) {
    return a.value< b.value;
}

int main(){

    int n,x;
    vector<number> a(200000);
    int b[200000];
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>a[i].value;
        a[i].index=i;
        b[i]=a[i].value;
    }
    sort(a.begin(),a.begin()+n,cmp);
    for(int i=0;i<n;i++){
        if(binary_search(a,x-b[i],0,n-1,i) != -1){  // 传入下标 i
            cout<<i+1<<" "<<binary_search(a,x-b[i],0,n-1,i);
            return 0;
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}
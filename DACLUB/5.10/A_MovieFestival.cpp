//
// Created by 14653 on 24-5-10.
//

#include "A_MovieFestival.h"
#include<iostream>
#include<algorithm>
#include<array>
#include<vector>
using namespace std;
struct tim{
    int start;
    int end;
    int count;
};
bool cmp(struct tim& a, struct tim & b){
    return a.start<b.start;
}

int main() {
    int n;
    cin >> n;
    vector<struct tim> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].start >> a[i].end;
        a[i].count = 0;
    }

    // 使用 std::sort 来排序时间
    sort(a.begin(), a.end(), cmp);

    // 初始化第一个电影的计数为 1
    a[0].count = 1;

    // 计算最大的电影观看序列
    for (int i = 1; i < n; i++) {
        int max_count = 0;
        for (int j = 0; j < i; j++) {
            if (a[i].start >= a[j].end && a[j].count > max_count) {
                max_count = a[j].count;
            }
        }
        a[i].count = max_count + 1;
    }

    // 寻找计数的最大值
    int max_count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].count > max_count) {
            max_count = a[i].count;
        }
    }

    cout << max_count;
    return 0;
}
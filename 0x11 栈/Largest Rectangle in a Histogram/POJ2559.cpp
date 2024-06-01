//
// Created by AaronPang on 6/1/24.
//
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
void LRH (int a[],int n){
    int w[n];
    int s[n+1],p=0;
    for (int i=0;i<n;i++){
        w[i]=1;
        s[i]=0;
    }
    s[n]=0;
    a[n]=0;
    for (int i=0 ;i<n;i++){
        cout<<a[i]<<' ';
    }
    s[0]=a[0];
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]>s[p]){
            p++;
            s[p]=a[i];
        }
        else{
            int width=1;
            while(a[i]<=s[p] && p>=0){
                width+=w[p];
                ans= max(ans,(width-1)*s[p]);
                p--;
            }
            s[++p]=a[i];
            w[p]=width;
        }
    }
    cout<<ans<<endl;
}
int main() {
    int n;
    cin >> n;
    while (n != 0) {
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        LRH(a, n);
        cin >> n;
    }
    return 0;
}
//#include <iostream>
//#include <vector>
//#include <stack>
//#include <algorithm>
//using namespace std;
//
//void LRH(vector<int>& a, int n) {
//    a.push_back(0); // 添加一个0确保最后的柱子被处理
//    stack<int> s;
//    int max_area = 0;
//
//    for (int i = 0; i < a.size(); ++i) {
//        while (!s.empty() && a[s.top()] >= a[i]) {
//            int height = a[s.top()];
//            s.pop();
//            int width = s.empty() ? i : (i - s.top() - 1);
//            max_area = max(max_area, height * width);
//        }
//        s.push(i);
//    }
//
//    cout << max_area << endl;
//}
//
//int main() {
//    int n;
//    cin >> n;
//    while (n != 0) {
//        vector<int> a(n);
//        for (int i = 0; i < n; ++i) {
//            cin >> a[i];
//        }
//        LRH(a, n);
//        cin >> n;
//    }
//    return 0;
//}

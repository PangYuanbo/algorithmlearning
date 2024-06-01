//
// Created by AaronPang on 6/1/24.
//
#include<iostream>
#include<queue>
#include<stack>
#include <thread> // 需要包含这个头文件
#include <chrono> // 需要包含这个头文件
using namespace std;
stack <int> a;
queue <int> q;
using namespace std;
int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        q.push(x);
    }
//    while (!q.empty()){
//        cout<<q.front()<<' ';
//    }
    a.push(q.front());
    q.pop();
    while(!q.empty()){
        if (q.front()>=a.top()){
            a.push(q.front());
            q.pop();
        }
        else{
            while(!a.empty() && q.front() < a.top()){ //注意这里不能写while (q.front() < a.top() && !a.empty())，如果a已经空了，那么q.front() < a.top()的比较会出现没有定义的问题
                q.push(a.top());
                a.pop();
            }

            a.push(q.front());
            q.pop();
        }
    }
    while(!a.empty()){
        q.push(a.top());
        a.pop();
    }
    while (!q.empty()){
        cout<<q.front()<<' ';
        q.pop();
    }
    return 0;
}
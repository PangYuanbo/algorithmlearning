//
// Created by 14653 on 5/16/2024.
////
//problem
//        维护一个整数序列的编辑器，支持5种操作，操作数< 1e6
//I x：在光标后插入数x，插入后光标移到x后
//        D:删除光标前的一个整数
//        L:光标左移一个位置
//        R:光标右移一个位置
//        Q k:询问k之前的最大前缀和，k不超过光标位置
//        solution
//特殊性：I,D,L,R都在光标位置修改。所以想到对顶栈。
//再开一个数组f维护栈A的前缀和的最大值即可。
//题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=4699
//                Sample Input
//                8
//                I 2
//                I -1
//                I 1
//                Q 3
//                L
//                D
//                R
//                Q 2
//                Sample Output
//                2
//                3

#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack <int> a,b;
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        char c;
        cin>>c;
        if (c=='I'){
            int x;
            cin>>x;
            a.push(x);
        }
        else if(c=='D'){
            a.pop();
        }
        else if(c=='L'){
            if (!a.empty()){
                b.push(a.top());
                a.pop();
            }
        }
        else if(c=='R'){
            if (!b.empty()){
                a.push(b.top());
                b.pop();
            }
        }
        else{

        }
    }
}
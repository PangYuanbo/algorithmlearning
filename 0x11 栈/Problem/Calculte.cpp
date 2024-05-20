//
// Created by 14653 on 5/19/2024.
//
//
// Created by AaronPang on 5/18/24.
//
#include<iostream>
#include<stack>
using namespace std;
stack <int> a;
int  main(){
    char x;
    cin>>x;
    double result;
    char plus = '+';
    char minus = '-';
    char multiply = '*';
    char divide = '/';
    a.push(x-'0');
    int count =x-'0';
    while (!a.empty()){
        cin>>x;
        if(x-'0'<=9 && x-'0'>=0){
            a.push(x-'0');
        }0
        else{
            int m,n;
            m=a.top();
            a.pop();
            n=a.top();
            a.pop();
            if (x==plus){
                a.push(count);
            }
            else if(x==minus){
                a.push(n-m);
            }
            else if(x==multiply){
                a.push(n*m);
            }
            else{
                a.push(n/m);
            }
        }
        result = a.top();
        a.pop();
        if (a.empty()){
            cout<<result<<endl;
            break;
        }
        else{
            a.push(result);
        }
    }
    return 0;
}
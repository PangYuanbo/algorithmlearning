//
// Created by 14653 on 5/19/2024.
//
#include<iostream>
#include<stack>
using namespace std;
int main(){
    string s;
    cin>>s;
    stack <char> a;
    for (int i=0;i<s.size();i++){
        if (s[i]>='0' && s[i]<='9'){
            cout<<s[i];
        }
        else if (s[i]=='('){
            a.push(s[i]);
        }
        else if (s[i]==')'){
            while (a.top()!='('){
                cout<<a.top();
                a.pop();
            }
            a.pop();
        }
        else{
            if (s[i]=='+' || s[i]=='-'){
                while (!a.empty() && a.top()!='('){
                    cout<<a.top();
                    a.pop();
                }
                a.push(s[i]);
            }
            else if (s[i]=='*' || s[i]=='/'){
                while (!a.empty() && (a.top()=='*' || a.top()=='/')){
                    cout<<a.top();
                    a.pop();
                }
                a.push(s[i]);
            }
        }
    }
}
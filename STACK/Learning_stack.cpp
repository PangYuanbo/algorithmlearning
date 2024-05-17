//
// Created by 14653 on 5/16/2024.
//
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Stack{
private:
    vector<int> stack;
public:
    void push (int value){
        stack.push_back(value);
    }
    void pop(){
        if (!stack.empty()){
            stack.pop_back();
        }
        else{
            cout<<"The stack is empty!"<<endl;
        }
    }
    int top(){
        if (!stack.empty()){
            return stack.back();
        }
        else{
            cout<<"The stack is empty!"<<endl;
            return -1;
        }
    }
    bool empty(){
        return stack.empty();
    }
};
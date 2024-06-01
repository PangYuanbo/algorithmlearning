//
// Created by AaronPang on 6/1/24.
//
#include<iostream>
#define MAXN 5
using namespace std;
int queue[MAXN];
int front=0,rear=0;
bool empty(){
    if(front==rear){
        return true;
    }
    else{
        return false;
    }
}
bool full(){
    if((rear+1)%MAXN==front){
        return true;
    }
    else{
        return false;
    }
}
void addqueue(int value){
    rear=(rear+1)%MAXN;
    queue[rear]=value;
}
int main(){

}
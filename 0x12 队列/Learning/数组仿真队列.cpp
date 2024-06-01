//
// Created by AaronPang on 6/1/24.
//
#include<iostream>
using namespace std;
int queue[6]={0};
int front=-1,rear=-1;
bool empty(int queue[]){
    if(front==rear){
        return true;
    }
    else{
        return false;
    }
}
void display(int queue[]){
    for (int i=front;i<=rear;i++){
        cout<<queue[i]<<' ';
    }
    cout<<endl;
}
void enter(int queue[],int q){
    queue[++rear]=q;
}
void delet(int queue[]){
    front++;
}
int gethead(int queue[]){
    return queue[rear];
}
int main(){

}
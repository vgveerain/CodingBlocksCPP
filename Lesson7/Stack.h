//linked list was continued in lesson 7.
//we've created header files in this lesson.
#include<iostream>
#include<vector>
#include "Node.h"

using namespace std;

template<typename T>

class Stack{
    node<T>* head;
    int count;
public:
    Stack(){
        head=NULL;
        count=0;
    }

    void push(T d){
        if(head==NULL){
            head = new node<T>(d);
            count++;
        }else{
            node<T> *n = new node<T>(d);
            n->next = head;
            head = n;
            count++;
        }
    }

    void pop(){
        if(head==NULL){
            return;
        }else{
            node<T> *temp = head;
            head=head->next;
            delete temp;
            count--;
        }
    }

    T top(){
        if(empty()){
            cout<<"Stack UnderFlow!"<<endl;
            return -1;
        }else{
            return head->data;
        }
    }

    bool empty(){
        if(head==NULL){
            return true;
        }else{
            return false;
        }
    }
};

template<typename T>


class StackV{
    vector<T> v;
public:
    void push(T d){
        v.push_back(d);
    }
    void pop(){
        v.pop_back();
    }
    T top(){
        if(empty()){
            cout<<"Stack UnderFlow!"<<endl;
            return -1;
        }else{
            return v[v.size()-1];
        }
    }
    bool empty(){
        if(v.size()){
            return true;
        }else{
            return false;
        }
    }
};

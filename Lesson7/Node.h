#include<iostream>

using namespace std;

template<typename T>

class node{
public:
    T data;
    node* next;
    node(T x):data(x), next(NULL){}
};

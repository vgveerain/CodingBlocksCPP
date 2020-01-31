#include<iostream>
#include<string>

using namespace std;

template<typename T>
class Node{
public:
    string key;
    T value;
    Node<T> *next;

    Node(String key, T value):value(value), key(key), next(NULL){}

    ~Node(){
        if(next!=NULL){
            delete next;
        }
    }
};

template<typename T>
class Hashtable{
    int currentSize;
    int tableSize;
    Node<>
};
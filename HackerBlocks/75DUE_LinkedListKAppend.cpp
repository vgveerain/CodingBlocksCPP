#include<bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int x):data(x), next(NULL){}

    int length(Node* head){
        Node* temp = head;
        int x=0;
        while(temp){
            temp = temp->next;
            x++;
        }
        return x;
    }

    void print(Node* head){
        while(head){
            cout<<head->data<<" ";
            head = head->next;
        }
    }
};

int main(){

    int x;
    cin>>x;
    int a;
    Node *head, *tail;
    Node *temp;
    for(int i=0;i<x;i++){
        cin>>a;
        if(i==0){
            head = new Node(a);
            tail = head;
        }else{
            temp = new Node(a);
            tail->next = temp;
            tail = temp;
        }
    }
    int z;
    cin>>z;
    temp = head;
    int len = head->length(head);

    if(z>len){
        z = z%len;
    }

    while(temp->length(temp)>z+1){
        temp = temp->next;
        // cout<<"here";
    }

    tail->next = head;
    head = temp->next;
    temp->next = NULL;

    head->print(head);

    return 0;
}

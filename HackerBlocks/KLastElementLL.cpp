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
    Node *head, *tail;
    Npde *temp;
    do{
        int z;
        cin>>z;
        if(z!=-1){
            if(head == NULL){
                temp = new Node()
            }
        }
    }while();
    return 0;
}

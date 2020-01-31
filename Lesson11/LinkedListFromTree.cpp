#include<bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    Node *left, *right;

    Node(int d):data(d), left(NULL), right(NULL){}
};

class LinkedListPair{
public:
    Node* head;
    Node* tail;
};

LinkedListPair BSTtoLL(Node* root){
    LinkedListPair l;
    if(root == NULL){
        l.head = NULL;
        l.tail = NULL;
        return l;
    }

    if(root->left!=NULL && root->right == NULL){
        LinkedListPair left = BSTtoLL(root->left);
        left.tail->right = root;
        l.head = left.head;
        l.tail = root;
    }else if(root->left==NULL && root->right != NULL){
        LinkedListPair right = BSTtoLL(root->right);
        l.head = root;
        root->right = right.head;
        l.tail = right.tail;
        return l;
    }else if(root->left ==  NULL && root->right == NULL){
        l.head = root;
        l.tail = root;
        return l;
    }else{
        LinkedListPair left = BSTtoLL(root->left);
        LinkedListPair right = BSTtoLL(root->right);

        left.tail = root;
        root->right = right.head;

        l.head = left.head;
        l.tail = right.tail;
        return l;
    }
}

Node* buildBalanced(int *a, int s, int e){
    //uses a sorted array to build a balanced binary tree
    if(s>e){
        return NULL;
    }

    int mid = (s+e) /2;
    Node *n = new Node(a[mid]);
    n->left = buildBalanced(a, s, mid-1);
    n->right = buildBalanced(a, mid+1, e);
    return n;
}

void printLL(Node* root){
    if(root->right!=NULL){
        cout<<"->"<<root->data;
        printLL(root->right);
    }else{
        return;
    }
}

int main(){
    // Node *temp = new Node(100);
    // cout<<temp->data;
    Node *root;
    int ar[11] = {1,2,3,4,5,6,7,8,9,10,11};
    root = buildBalanced(ar,0,10);
    LinkedListPair ll = BSTtoLL(root);
    printLL(ll.head);
    return 0;
}

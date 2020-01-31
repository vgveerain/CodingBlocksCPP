#include<bits/stdc++.h>
#include<climits>

using namespace std;

//BST
/*
    So the nodes on the left can be less than or equal to the root node.
    The right is always greater than the root.
*/

class Node{
public:
    int data;
    Node *left, *right;

    Node(int d):data(d), left(NULL), right(NULL){}
};

// balanced tree -> only if
// |Height of the left subtree - Height of the right subtree| <= 1

class Pair{
public:
    int height;
    bool isBalanced;
};

void LevelOrder(Node *root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                //if queue not empty then push null again.
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

Node* insertInBST(int d, Node* root){
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d < root->data){
        root->left = insertInBST(d, root->left);
    }else{
        root->right = insertInBST(d, root->right);
    }
    return root;
}

Node* buildTree(){
    Node* root = NULL;
    int data;
    cin>>data;
    while(data != -1){
        root = insertInBST(data, root);
        cin>>data;
    }
    return root;
}

Node* search(Node* root, int d){
    // cout<<"here - "<<root->data<<" - "<<d;
    if(root == NULL){
        cout<<"Not Found!"<<endl;
        return NULL;
    }

    if(root->data == d){
        return root;
    }

    if(root->data > d){
        return search(root->left, d);
    }else{
        return search(root->right, d);
    }
}

bool isBST(Node* root, int ll=INT_MIN, int ul=INT_MAX){
    if(root == NULL){
        return true;
    }
    if(root->data >= ll && root->data <= ul && isBST(root->left, ll, root->data) && isBST(root->right, root->data, ul)){
        return true;
    }else{
        return false;
    }
}

// balanced tree -> only if
// |Height of the left subtree - Height of the right subtree| <= 1

Pair checkIfBalanced(Node *root){
    Pair p;
    if(root == NULL){
        p.height = 0;
        p.isBalanced = true;
        return p;
    }else{
        Pair l = checkIfBalanced(root->left);
        Pair r = checkIfBalanced(root->right);

        int x = l.height - r.height;
        if(l.isBalanced && r.isBalanced && abs(x)<=1){
            p.isBalanced = true;
        }else{
            p.isBalanced = false;
        }
        p.height = 1+max(l.height, r.height);
        return p;
    }
}

// Node* buildBalanced(Node* root, int *ar, int n){
//     int mid;
//     if(n%2==0){
//         mid = n/2;
//     }else{
//         mid = 1+n/2;
//     }
//     if(n>1){
//         root = new Node(ar[mid]);
//         root->left = buildBalanced(root->left, ar, mid);
//         root->right = buildBalanced(root->right, ar+mid, n-mid);
//     }else if(n==1){
//         root = new Node(ar[mid]);
//     }
//     return root;
// }

Node* buildBalanced(int *a, int s, int e){
    //uses a sorted array to build a balanced binary tree.c
    if(s>e){
        return NULL;
    }

    int mid = (s+e) /2;
    Node *n = new Node(a[mid]);
    n->left = buildBalanced(a, s, mid-1);
    n->right = buildBalanced(a, mid+1, e);
    return n;
}

int main(){
    Node *root;
    // root =  buildTree();
    // LevelOrder(root);

    //====SEARCH_BST=======//
    // int k;
    // cin>>k;
    // Node *temp = search(root, k);
    // cout<<temp->data;

    //====IS_BALANCED======//
    // if(checkIfBalanced(root).isBalanced){
    //     cout<<"isBST"<<endl;
    // }else{
    //     cout<<"isNotBST"<<endl;
    // }

    //======BUILD_BALANCED======//
    int ar[7] = {1,2,3,4,5,6,7};
    // root = buildBalanced(root, ar, 7);
    root = buildBalanced(ar,0,6);
    LevelOrder(root);
    return 0;
}

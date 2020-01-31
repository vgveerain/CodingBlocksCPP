#include<bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    Node *left, *right;

    Node(int d):data(d), left(NULL), right(NULL){}
};

void preOrder(Node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(Node* root){
    if(root == NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
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

int index1 = 0;
Node* inPretree(int *pre, int *in, int s, int e){

    if(s>e){
        return NULL;
    }

    int data = pre[index1];
    index1++;

    Node* root = new Node(data);
    int k=-1;
    for(int i=s; i<=e; i++){
        if(data == in[i]){
            k=i;
            break;
        }
    }

    root->left = inPretree(pre, in, s, k-1);
    root->right = inPretree(pre, in, k+1, e);

    return root;
}

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

int main(){

    int pre[] = {8,10,1,6,4,7,3,14,13};
    int in[] = {1,10,4,6,7,8,3,13,14};

    Node *root = inPretree(pre, in, 0, 8);
    LevelOrder(root);
    return 0;
}

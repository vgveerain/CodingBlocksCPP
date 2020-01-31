#include<bits/stdc++.h>

using namespace std;

class node{
public:
    int data;
    node *left, *right;
    int getData(){
        return data;
    }

    node(int d):data(d), left(NULL), right(NULL){}
};

int i=0;

node* buildTree(){
    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    }else{
        node* n = new node(data);
        n->left = buildTree();
        n->right = buildTree();
        return n;
    }
}

node* buildTree1(int x[]){
    int data;
    data = x[i];
    i++;

    if(data == -1){
        return NULL;
    }else{
        node *n = new node(data);
        n->left = buildTree1(x);
        n->right = buildTree1(x);
        return n;
    }
}

void preOrder(node* root){
    if(root==NULL){
        return;
    }else{
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(node* root){
    if(root==NULL){
        return;
    }else{
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
}

void inOrder(node* root){
    if(root==NULL){
        return;
    }else{
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

int countNodes(node* root){
    //base case
    if(root==NULL){
        return 0;
    }

    return 1+countNodes(root->left)+countNodes(root->right);
}

int height(node* root){
    if(root==NULL){
        return 0;
    }else{
        int leftH = height(root->left);
        int rightH = height(root->right);

        return 1+max(leftH, rightH);
    }
}

int levelOrder(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
                //pushing NULL at the end of every level, to mantain the level order printing.
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

void mirror(node* root){
    if(root==NULL){
        return;
    }else{
        swap(root->left, root->right);
        mirror(root->left);
        mirror(root->right);
    }
}

int diameter(node* root){
    if(root == NULL){
        return 0;
    }

    return max(height(root->left) + height(root->right)-1, max(diameter(root->left), diameter(root->right)));
}

class Pair{
public:
    int height;
    int diameter;
};

Pair fastDiameter(node* root){
    Pair p;
    if(root == NULL){
        p.height = p.diameter = 0;
        return p;
    }
    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);

    p.height = 1+max(left.height, right.height);
    int o1 = left.height + right.height - 1;
    int o2 = left.diameter;
    int o3 = right.diameter;

    p.diameter = max(o1, max(o2, o3));
    return p;
}

void levelOrderBuild(node* &root){
    int data;
    cout<<"Enter the root node: ";
    cin>>data;
    root = new node(data);
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        cout<<"enter the children of "<<temp->data<<" : ";
        int c1, c2;
        cin>>c1>>c2;
        if(c1!=-1){
            temp->left = new node(c1);
            q.push(temp->left);
        }
        if(c2!=-1){
            temp->right = new node(c2);
            q.push(temp->right);
        }
    }
}

int main(){
    node *root = NULL;
    int x[20] = {8,10,1,-1,-1,6,4,-1,-1,7,-1,-1,3,-1,14,13,-1,-1,-1};
    root = buildTree1(x);
    preOrder(root);
    cout<<endl;
    // postOrder(root);
    // cout<<endl;
    // inOrder(root);
    // cout<<countNodes(root);
    // cout<<height(root);
    // levelOrder(root);
    // mirror(root);
    levelOrder(root);
    cout<<fastDiameter(root).diameter<<endl;
    // cout<<diameter(root);
}
#include<bits/stdc++.h>

using namespace std;

class Node{
public:
    bool isTerminal;
    char data;
    unordered_map<char, Node*> h;

    Node(char d){
        data = d;
        isTerminal = false;
    }
};

class Trie{
    Node *root;
public:
    Trie(){
        root = new Node('\0');
    }

    void addWord(char *word){
        Node *temp = root;
        for(int i=0;word[i]!='\0';i++){
            char ch = word[i];
            if(temp->h.count(ch)==0){
                temp->h[ch] = new Node(ch);
                temp = temp->h[ch];
            }else{
                temp = temp->h[ch];
            }
        }
        temp->isTerminal = true;
    }

    bool searchWord(char *word){
        Node *temp = root;
        for(int i=0;word[i]!='\0';i++){
            char ch=word[i];
            if(temp->h.count(ch)==0){
                return false;
            }else{
                temp = temp->h[ch];
            }
        }
        return temp->isTerminal;
    }
};

int main(){
    Trie t;
    t.addWord("Code");
    t.addWord("Coder");
    t.addWord("Hell");
    t.addWord("Hello");

    while(1){
        char ch[100];
        cin>>ch;
        if(t.searchWord(ch)==true){
            cout<<"exists"<<endl;
        }else{
            cout<<"doesn't exist"<<endl;
        }
    }

    return 0;
}

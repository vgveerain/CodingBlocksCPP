#include<bits/stdc++.h>

using namespace std;

void print(priority_queue<int, vector<int>, greater<int>> h, int x){
    while(!h.empty()){
        cout<<h.top()<<" ";
        h.pop();
    }
}

void pushTop(priority_queue<int, vector<int>, greater<int>> h, int k, int x){
    if(h.size() <= k){
        h.push(x);
    }else if(h.top() < x){
        h.pop();
        h.push(x);
    }
    return;
}

int main(){
    priority_queue<int, vector<int>, greater<int>> h;
    int k=3;

    while(1){
        int x;
        cin>>x;
        if(x==-1){
            print(h,k);
        }
        pushTop(h,k,x);
    }
    return 0;
}

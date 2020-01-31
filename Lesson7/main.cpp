#include<bits/stdc++.h>
#include "Stack.h"
#include<stack>

using namespace std;

int main(){
    // Stack s; //that's our implementation
    Stack<int> s; //that's our implementation with a template
    // StackV<int> s; //that's our implementation with a vector
    // stack<int> s;

    for(int i=0;i<6;i++){
        s.push(i);
    }

    while (!s.empty()) {
        cout<<s.top()<<endl;
        s.pop();
    }
}

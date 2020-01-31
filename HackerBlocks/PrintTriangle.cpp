#include<bits/stdc++.h>

using namespace std;

void printTriangle(int x){
    if(x==0){
        return;
    }
    printTriangle(x-1);
    for(int i=0;i<x;i++){
        cout<<"* ";
    }
    cout<<endl;
}

void printInvertedTriangle(int x){
    if(x==0){
        return;
    }
    // printTriangle(x-1);
    for(int i=0;i<x;i++){
        cout<<"* ";
    }
    cout<<endl;
    printInvertedTriangle(x-1);
}

int main(){

    int x;
    cin>>x;

    // printTriangle(x);
    printInvertedTriangle(x);

    return 0;
}

#include<bits/stdc++.h>

using namespace std;

bool checkIfSorted(int *a, int n){
    if(n==1){
        return true;
    }else{
        bool ans = false;
        if(a[0]<=a[1]){
            ans = true;
        }
        return (ans && checkIfSorted(a+1, n-1));
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(checkIfSorted(a,n)){
        cout<<"true";
    }else{
        cout<<"false";
    }
    return 0;
}

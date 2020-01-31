#include<bits/stdc++.h>

using namespace std;

int factorial(int x){
    if(x==0){
        return 1;
    }

    if(x<0){
        return 0;
    }

    return x*factorial(x-1);
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    int ans[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int result = 0;
    for(int i=0;i<n;i++){
        ans[i] = factorial(arr[i]);
        result += ans[i];
    }

    result %= 107;
    cout<<result;
    return 0;
}

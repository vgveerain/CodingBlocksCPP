#include<bits/stdc++.h>

using namespace std;

int moveXAtEnd(char *a, int n){
    //base case
    if(n==0){
        return 0;
    }

    //recursisve case
    if(a[0] == 'x'){
        for(int i=0;i<n-1;i++){
            a[i] = a[i+1];
        }
        int count = 1+moveXAtEnd(a, n-1);
        return count;
    }else{
        int count = moveXAtEnd(a+1,n-1);
        return count;
    }

}

int main(){
    char a[100];
    cin>>a;
    int n = strlen(a);
    int count = moveXAtEnd(a,n);
    for(int i=n-count; i<n; i++){
        a[i] = 'x';
    }
    cout<<a;
    return 0;
}

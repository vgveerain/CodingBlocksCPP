#include<bits/stdc++.h>

using namespace std;

char* recursionFormatting(char *a, int n){
    //base case
    if(n==1){
        return a;
    }

    //recursive case
    if(a[0] == a[1]){
        char* temp = new char[n+1];
        temp[0] = a[0];
        temp[1] = '*';
        temp[2] = a[1];
        for(int i=3;i<n+1;i++){
            temp[i] = a[i-1];
        }
        return recursionFormatting(temp+2, n-1);
    }else{
        return recursionFormatting(a+1, n-1);
    }
}

int main(){
    char a[100];
    cin>>a;
    int n = strlen(a);
    char *out = recursionFormatting(a,n);
    for(int i=0;i<2;i++){
        cout<<out[i];
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

int* allIndices(int *a, int n, int m){
    //base case
    if(n==1 && a[0]!=m){
        cout<<"here";
        return NULL;
    }else if(n==1){
        int *temp = new int[1];
        temp[0] = n;
        return temp;
    }
    //recursive case
    int *temp = allIndices(a+1,n-1,m);
    if(temp==NULL){
        return temp;
    }
    int s = sizeof(temp)/sizeof(int);
    if(a[0] == m){
        cout<<"here";
        int *x = new int[s+1];
        x[0] = n;
        int i=1;
        int j=0;
        for(i;i<s;i++){
            x[i] = temp[j];
            j++;
        }
        return x;
    }else{
        return temp;
    }
}

int main(){
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    int m;
    cin>>m;

    int *arr = allIndices(ar,n,m);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }

}

#include<bits/stdc++.h>

using namespace std;

void Merge(int *a, int *x, int *y, int start, int end){
    int i=start;
    int mid = (start + end)/2;
    int j=mid+1;
    int k=start;

    while(i<=mid && j<=end){
        if(x[i]<y[j]){
            a[k]=x[i];
            k++;
            i++;
        }else{
            a[k]=y[j];
            k++;
            j++;
        }
    }

    while(j<=end){
        a[k]=y[j];
        k++;
        j++;
    }

    while(i<=mid){
        a[k]=x[i];
        i++;
        k++;
    }
}

void MergeSort(int *a, int start, int end){
    //base case
    if(start >= end){
        return;
    }

    //divide
    int x[100], y[100];
    int mid = (start + end)/2;
    for(int i=0;i<=mid;i++){
        x[i]=a[i];
    }
    for(int i=mid+1;i<=end;i++){
        y[i]=a[i];
    }

    //sort
    MergeSort(x,start,mid);
    MergeSort(y,mid+1,end);

    //merge
    Merge(a, x, y, start, end);
}

int main(){
    int a[] = {5,3,1,0,6,4};
    int n = sizeof(a)/sizeof(int);

    MergeSort(a,0,n-1);
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
}

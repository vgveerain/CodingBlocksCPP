#include<bits/stdc++.h>

using namespace std;

int BinarySearch(int a[], int start, int end, int key){
    if(start>end){
        return -1;
    }
    int mid = (start+end)/2;
    if(key<a[mid]){
        return BinarySearch(a, start, mid-1, key);
    }else if(key == a[mid]){
        return mid;
    }else if(key>a[mid]){
        return BinarySearch(a, mid+1, end, key);
    }
}

int main(){
    int a[]={1,3,5,7,9,11,13,15,17};
    int n=sizeof(a)/sizeof(int);

    cout<<BinarySearch(a,0,n-1,10);

    return 0;
}

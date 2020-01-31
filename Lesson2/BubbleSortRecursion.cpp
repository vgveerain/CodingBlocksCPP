#include<bits/stdc++.h>

using namespace std;

void BubbleSort(int *a, int len, int i){
    //base case
    if(i==(len-1)){
        return;
    }
    //recursive case
    for(int z=0; z<=len-2-i; z++){
        if(a[z] > a[z+1]){
            swap(a[z],a[z+1]);
        }
    }
    BubbleSort(a, len, i++);
}

int main(){

    int a[]={5,6,7,4,3,2,1};
    int n = sizeof(a)/sizeof(int);

    BubbleSort(a, n, 0);

    for(int i=0;i<n;i++){
        cout<<a[i];
    }

    return 0;
}

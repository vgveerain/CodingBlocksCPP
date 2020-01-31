#include<bits/stdc++.h>

using namespace std;

int main(){

    int x;
    cin>>x;

    int arr[x];
    int y;

    for(int i=0;i<x;i++){
        cin>>y;
        if(i==0){
            arr[i]=y;
        }else{
            int z=0;
            while(arr[z]<=y && z<x){
                z++;
            }
            int temp = arr[z];
            arr[z] = y;
            z++;
            int as=i-1;
            while(as>z){
                arr[as+1] = arr[as];
                as--;
            }
            arr[z] = temp;
        }
    }

    for(int i=0;i<x;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
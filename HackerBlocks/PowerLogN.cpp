#include<bits/stdc++.h>

using namespace std;

int power(int x, int n){
    if(n==1){
        return x;
    }else{
        return x*power(x,n-1);
    }
}

int powerLogN(int x, int n){
    int ans = 1;
    while(n>0){
        if(n%2!=0){
            ans = ans * x;
        }

        n = n/2;
        x = x*x;
    }
    return ans;

}

int main(){
    int x,n;
    cin>>x;
    cin>>n;
    cout<<powerLogN(x,n);
    return 0;
}

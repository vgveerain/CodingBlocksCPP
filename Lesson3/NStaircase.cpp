#include<bits/stdc++.h>

using namespace std;

/*
    Kid at the bottom of the staircase, mom at the top of the staircase.
    kid takes k steps at max, k=3 here.
    find the total no. of ways to reach his mom.

    to find all combinations of 1,2,3 such that sum is n.

    all possible ways to reach nth stair is sum of all the ways to reach n-k stairs, n-k+1, n-k+2...n-1.

    f(n) = f(n-1)+f(n-2)+f(n-3)+...f(n-k);
*/

int NStair(int n, int k){
    //base case
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }

    //recursive case
    int sum=0;
    for(int i=1;i<=k;i++){
        sum+=NStair(n-i,k);
    }
    return sum;
}

int main(){

    int n;
    cin>>n;
    int k;
    cin>>k;

    cout<<NStair(n,k)<<endl;

    return 0;
}

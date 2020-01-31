#include<bits/stdc++.h>

using namespace std;

int dp[100][100]={-1};

int knapsack_TopDown(int *wts, int *prices, int n, int capacity, int dp[][100]){
    if(n==0||capacity==0){
        dp[n][capacity] = 0;
        return dp[n][capacity];
    }

    if(dp[n][capacity] != -1){
        return dp[n][capacity];
    }else{
        int inc=0, exc=0;
        if(wts[n-1]<=capacity){
            inc=prices[n-1]+knapsack_TopDown(wts, prices, n-1, capacity-wts[n-1], dp);
        }
        exc = knapsack_TopDown(wts, prices, n-1, capacity, dp);

        dp[n][capacity] = max(inc, exc);
        return dp[n][capacity];
    }
}

int knapsack_BottomUp(int *wts, int *prices, int n, int capacity, int dp[][100]){
    for(int i=0;i<n;i++){
        for(int c=0;c<=capacity;c++){
            if(i==0 || c==0){
                dp[i][c]=0;
            }else{
                int inc=0, exc=0;
                if(wts[i-1]<=c){
                    inc = prices[i-1]+dp[i-1][c-wts[i-1]];
                }
                exc = dp[i-1][capacity];
                dp[i][c] = max(inc, exc);
            }
        }
    }
    return dp[n][capacity];
}

int knapsack(int *wts, int *prices, int n, int capacity){
    if(n==0 || capacity == 0){
        return 0;
    }

    int inc=0, exc=0;
    if(wts[n-1]<=capacity){
        inc=prices[n-1]+knapsack(wts, prices, n-1, capacity-wts[n-1]);
    }
    exc = knapsack(wts, prices, n-1, capacity);

    return max(inc, exc);
}

int main(){
    int wts[] = {7,4,4};
    int prices[] = {15,8,8};
    int n=3;
    int capacity;
    cin>>capacity;
    // cout<<knapsack_TopDown(wts, prices, n, capacity,dp)<<endl;
    cout<<knapsack_BottomUp(wts, prices, n, capacity, dp);
    return 0;
}

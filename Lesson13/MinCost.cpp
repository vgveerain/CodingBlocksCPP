#include<bits/stdc++.h>

using namespace std;

int dp[10][10];
int a[][10] = {
    {1,2,5,1},
    {8,3,6,2},
    {0,1,3,3},
    {4,1,7,2}
};

//top down
int minCost_TopDown(int a[][10], int i, int j){
    if(i==0 && j==0){
        return a[i][j];
    }else if(i==0 && j>0){
        return a[i][j]+minCost_TopDown(a, i, j-1);
    }else if(i>0 && j==0){
        return a[i][j]+minCost_TopDown(a, i-1, j);
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }else{
        int op1 = a[i][j] + minCost_TopDown(a,i,j-1);
        int op2 = a[i][j] + minCost_TopDown(a,i-1,j);
        int ans = min(op1, op2);
        // return ans;
        dp[i][j] = ans;
        return dp[i][j];
    }
}

//bottom up
int minCost_BottomUp(int a[][10], int x, int y){
    // if(i==0 && j==0){
    //     return a[i][j];
    // }else if(i==0 && j>0){
    //     return a[i][j]+minCost(a, i, j-1);
    // }else if(i>0 && j==0){
    //     return a[i][j]+minCost(a, i-1, j);
    // }
    //
    // if(dp[i][j] != -1){
    //     return dp[i][j];
    // }else{
    //     int op1 = a[i][j] + minCost(a,i,j-1);
    //     int op2 = a[i][j] + minCost(a,i-1,j);
    //     int ans = min(op1, op2);
    //     // return ans;
    //     dp[i][j] = ans;
    //     return dp[i][j];
    // }

    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            if(i==0 && j==0){
                dp[i][j] = a[i][j];
            }else if(i==0 && j>0){
                dp[i][j] = a[i][j]+dp[i][j-1];
            }else if(j==0 && i>0){
                dp[i][j] = a[i][j]+dp[i-1][j];
            }else{
                int op1 = a[i][j] + minCost_BottomUp(a,i,j-1);
                int op2 = a[i][j] + minCost_BottomUp(a,i-1,j);
                int ans = min(op1, op2);
                dp[i][j] = ans;
            }
        }
    }
    return dp[x][y];
}

int main(){
    memset(dp,-1,sizeof(dp));
    int x,y;
    cin>>x>>y;
    cout<<minCost_BottomUp(a,x,y)<<endl;
    return 0;
}

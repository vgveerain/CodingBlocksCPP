#include<bits/stdc++.h>

using namespace std;

//bottom up
int totalWays(int x, int y){
    int dp[100][100] = {0};
    for(int i=0;i<=x;i++){
        dp[i][0] = 1;
    }
    for(int j=0;j<=y;j++){
        dp[0][j] = 1;
    }
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }
    return dp[x][y];
}

int elephantWays(int x, int y){
    int dp[100][100] = {0};
    dp[0][0] = 1;
    int ans = 1;
    for(int i=1;i<=x;i++){
        dp[0][i] = ans;
        ans *=2;
    }
    ans=1;
    for(int j=1;j<=y;j++){
        dp[j][0] = ans;
        ans *=2;
    }
    ans=0;
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            int zans = 0;
            for(int z=0;z<i;z++){
                zans+=dp[z][j];
            }
            for(int z=0;z<j;z++){
                zans+=dp[i][z];
            }
            dp[i][j] = zans;
        }
    }
    return dp[x][y];
}

int main(){
    int x,y;
    cin>>x>>y;
    // cout<<totalWays(x,y)<<endl;
    cout<<elephantWays(x,y)<<endl;
    return 0;
}

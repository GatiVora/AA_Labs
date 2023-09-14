
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int n=4;

bool dynamic_knapsack(int p[],int w[],int c ,int v){
    int dp[n+1][c+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=c;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=c;j++){
            if(j<w[i]){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max((p[i]+dp[i-1][j-w[i]]),dp[i-1][j]);
            }
        }
    }
  
    if(dp[n][c]==v)
        return true;
    else
        return false;
}

int main()
{
    int sos[]={2,4,6,8};
    int sum=8;
    cout<<dynamic_knapsack(sos,sos,sum,sum);
    

    return 0;
}

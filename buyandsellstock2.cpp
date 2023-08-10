#include<bits/stdc++.h>
using namespace std;
// we can furthur space optimise it also either by using two 2 sized array or 4 variables.
long func(int i, int buy, long *values, int n,vector<vector<long>> &dp) {
    if(i==n) return 0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    long profit = 0;
    if (buy) {
        profit =max(-values[i] + func(i+1,0,values,n,dp),0+func(i+1,1,values,n,dp));
    } else {
        profit = max(values[i] + func(i+1,1,values,n,dp),0+func(i+1,0,values,n,dp));

    }
    return dp[i][buy] = profit;
}

long getMaximumProfit(long *values, int n)
{
    //Write your code here
    // vector<vector<long>> dp(n,vector<long>(2,-1));
    // return func(0,1,values,n,dp);
    vector<vector<long>> dp(n+1,vector<long>(2,0));
    dp[n][0]=0;
    dp[n][1]=0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= 1; j++) {
            long profit = 0;
            if (j) {
                profit =max(-values[i] + dp[i+1][0],0+dp[i+1][1]);
            } else {
                profit = max(values[i] + dp[i+1][1],0+dp[i+1][0]);

            }
            dp[i][j] = profit;
        }
    }
    return dp[0][1];



}
int main(){




    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int func(int i,int buy , int cap ,vector<int> &values,int n,vector<vector<vector<int>>> &dp){
    if(i==n || cap==0) return 0;
    if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
    int profit =0;
    if (buy) {
        profit =max(-values[i] + func(i+1,0,cap,values,n,dp),0+func(i+1,1,cap,values,n,dp));
    } else {
        profit = max(values[i] + func(i+1,1,cap-1,values,n,dp),0+func(i+1,0,cap,values,n,dp));

    }
    return dp[i][buy][cap] = profit;
}









int maxProfit(vector<int>& values)
{
    // Write your code here.
    int n = values.size();
    // vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    // return func(0,1,2,prices,n,dp);
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    for (int i = n - 1; i >= 0; i--) {
        for (int buy = 0; buy <= 1; buy++) {
          for (int cap = 1; cap <= 2; cap++) {
                int profit =0;
                if (buy) {
                    profit =max(-values[i] + dp[i+1][0][cap],0+dp[i+1][1][cap]);
                } else {
                    profit = max(values[i] + dp[i+1][1][cap-1],0+dp[i+1][0][cap]);

                }
                dp[i][buy][cap] = profit;
          }
        }
    }
    return dp[0][1][2];
}

int main(){




    return 0;
}
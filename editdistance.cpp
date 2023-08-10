#include<bits/stdc++.h>
using namespace std;
// in the question of trying all possible ways we generally ahve exponential time complexity in nature.
// have solved this queastion full from the recursion , memoisation to the tabulation .
// however we can furthur space optimise it also.


int func(int i, int j, string &str1, string &str2 , vector<vector<int>> &dp) {
    if(i==0) return j;
    if(j==0) return i;
    if(dp[i][j]!=-1) return dp[i][j];
    if(str1[i-1]==str2[j-1]) return dp[i][j] = func(i-1,j-1,str1,str2 ,dp);
    return dp[i][j] = 1+min(func(i-1,j,str1,str2,dp),min(func(i,j-1,str1,str2,dp),func(i-1,j-1,str1,str2,dp)));
}

int editDistance(string str1, string str2)
{
    //write you code here
    int n = str1.size();
    int m = str2.size();
    // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    // return func(n,m ,str1 ,str2 ,dp);
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for (int j = 0; j <= m; j++) {
        dp[0][j] = j;
    }
    for (int j = 0; j <= n; j++) {
        dp[j][0] = j;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(str1[i-1]==str2[j-1])  dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
        }
    }
    return dp[n][m];
}
int main(){







    return 0;
}
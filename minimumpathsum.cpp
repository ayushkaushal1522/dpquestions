#include <bits/stdc++.h>
using namespace std;

// solved the minimum path sum  using all the three approaches.
// which are memoization , tabulation and the space optimisation as well.


int func(int i, int j, vector<vector<int>> grid ,vector<vector<int>> &dp) {
    if(i==0 && j==0) return grid[0][0];
    if(i<0 || j<0) return 1e9;
    if(dp[i][j]!=-1) return dp[i][j];
    int left = grid[i][j] + func(i ,j-1,grid,dp);
    int up = grid[i][j]+func(i-1,j,grid,dp);
    return dp[i][j] = min(left,up);
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    
    int n=grid.size();
    int m=grid[0].size();
    // vector<vector<int>> dp(n,vector<int>(m,-1));
    // return func(n-1,m-1,grid,dp);

    // vector<vector<int>> dp(n,vector<int>(m,0));
    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < m; j++) {
    //         if(i==0 && j==0) dp[0][0] = grid[0][0];
    //         else {
    //             int left=1e9;
    //             int up = 1e9;
    //             if(j>0) left = grid[i][j] + dp[i][j-1];
    //             if(i>0) up = grid[i][j]+dp[i-1][j];
    //             dp[i][j] = min(left,up);
    //         }
            
            
    //   }
    // }
    vector<int> prev(m,0);
    for (int i = 0; i < n; i++) {
      vector<int> curr(m,0);
      for (int j = 0; j < m; j++) {
            if(i==0 && j==0) curr[0] = grid[0][0];
            else {
                int left=1e9;
                int up = 1e9;
                if(j>0) left = grid[i][j] + curr[j-1];
                if(i>0) up = grid[i][j]+prev[j];
                curr[j] = min(left,up);
            }
            
            
      }
      prev=curr;
    }
    return prev[m-1];

}
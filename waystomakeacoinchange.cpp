#include<bits/stdc++.h>
using namespace std;

// we have solved this question using all the three approaches which are simple recursion that is memoisation ,
// then the tabulation and then the space optimisation as well.


long func(int i, int target, int *arr , vector<vector<long>> &dp) {
  if (i == 0) {
      return (target%arr[0]==0);
  }
  if(dp[i][target]!=-1) return dp[i][target];
  long nottake = func(i-1 , target , arr,dp);
  long take  = 0;
  if(arr[i]<=target) take = func(i,target-arr[i],arr,dp);
  return dp[i][target] = take+nottake;
}
// long countWaysToMakeChange(int *arr, int n, int value)
// {
//     //Write your code here
//     // vector<vector<long>> dp(n,vector<long>(value+1,-1));
//     // return func(n-1,value,denominations,dp);
//     vector<vector<long>> dp(n,vector<long>(value+1,0));
//     for (int i = 0; i <= value; i++) {
//         dp[0][i] = (i%arr[0]==0);

//     }
//     for (int i = 1; i < n; i++) {
//         for (int j = 0; j <= value; j++) {
//             long nottake = dp[i-1][j];
//             long take  = 0;
//             if(arr[i]<=j) take =dp[i][j-arr[i]];
//             dp[i][j] = take+nottake;
//         }
//     }
//     return dp[n-1][value];
// }

long countWaysToMakeChange(int *arr, int n, int value)
{
    //Write your code here
    // vector<vector<long>> dp(n,vector<long>(value+1,-1));
    // return func(n-1,value,denominations,dp);
    vector<long> prev(value+1,0);
    for (int i = 0; i <= value; i++) {
        prev[i] = (i%arr[0]==0);

    }
    for (int i = 1; i < n; i++) {
        vector<long> curr(value+1,0);
        for (int j = 0; j <= value; j++) {
            long nottake = prev[j];
            long take  = 0;
            if(arr[i]<=j) take =curr[j-arr[i]];
            curr[j] = take+nottake;
        }
        prev = curr;
    }
    return prev[value];
}
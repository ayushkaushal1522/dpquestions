#include <bits/stdc++.h> 
// if there vare such sattements like infinite supply then we should 
// remain on the same index on which we reside uptowhen the base cased arrives.

int func(int i, int target, vector<int> &arr,vector<vector<int>> &dp) {
  if (i == 0) {
      if(target%arr[0]==0) return target/arr[0];
      else return 1e9;
  }
  if(dp[i][target]!=-1) return dp[i][target];
  int nottake = 0+func(i-1 ,target , arr,dp);
  int take = 1e9;
  if(arr[i]<=target) take = 1 + func(i,target-arr[i],arr,dp);
  return dp[i][target] = min(take , nottake);

}

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(x+1,-1));
    int ans = func(n-1 , x , num ,dp);
    if(ans==1e9) return -1;
    return ans;
}
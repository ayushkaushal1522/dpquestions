#include <bits/stdc++.h> 

int func(int i, int sum, vector<int> &arr , vector<vector<int>> &dp) {
	int mod = 1e9+7;
	if(sum==0) return 1;
	if(i==0) return arr[0]==sum;
	if(dp[i][sum]!=-1)
          return dp[i][sum];
    int nottake = func(i-1,sum,arr,dp);
	int take = 0;
	if(arr[i]<=sum) take = func(i-1,sum-arr[i],arr,dp);
	return dp[i][sum] = (take + nottake)%mod;
}

int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n= arr.size();
	vector<vector<int>> dp(n,vector<int>(k+1,-1));
	return func(n-1 , k ,arr ,dp);
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int total = 0;
    for(auto &it : arr) total+=it;
    if(total-d<0 || (total-d)%2) return false;
    return findWays(arr,(total-d)/2);

}



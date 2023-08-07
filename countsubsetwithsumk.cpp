//this problem gets being solved using the concept of pick and not pick only .
// and by just returning the count of it.
// it may give tle for large integer value so it is advisablle to use mod whwnever doing arithmetic 
// operation in it.
#include<bits/stdc++.h>
using namespace std;

int func(int i, int sum, vector<int> &arr , vector<vector<int>> &dp) {
	if(sum==0) return 1;
	if(i==0) return arr[0]==sum;
	if(dp[i][sum]!=-1)
          return dp[i][sum];
    int nottake = func(i-1,sum,arr,dp);
	int take = 0;
	if(arr[i]<=sum) take = func(i-1,sum-arr[i],arr,dp);
	return dp[i][sum] = take + nottake;
}

int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n= arr.size();
	vector<vector<int>> dp(n,vector<int>(k+1,-1));
	return func(n-1 , k ,arr ,dp);
}

int main(){





    return 0;
}
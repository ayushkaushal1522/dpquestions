// just by observing the dp table the answer of the present question can be finded out.
// and also with the help of same code just by making shuttle change in the code.




int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int totalsum=0;
    for (int i = 0; i < n; i++) {
        totalsum += arr[i];
    }
	int k = totalsum;
	vector<vector<bool>> dp(n,vector<bool>(k+1,0));
   
    for (int i = 0; i < n; i++) {
        dp[i][0]=true;
    }
   
    if(arr[0]<=k) dp[0][arr[0]]=true;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            bool notpick =dp[i-1][j];
            bool pick = false;
            if(arr[i]<=j) pick = dp[i-1][j-arr[i]];
            dp[i][j] = pick|notpick;
        }
    }
	int mini = 1e9;
    for (int i = 0; i <= totalsum / 2; i++) {
        if (dp[n - 1][i] == true) {
			mini = min(mini,abs(totalsum-i)-i);
        }
    }
	return mini;
}

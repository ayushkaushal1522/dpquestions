// this question is exactly same as that of the subset sum equal to k and can be achieved using the exact code just by making a shuttle change into it.


bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<bool> prev(k+1,0);
    // return func(n-1, k ,n,arr,dp);
    
    prev[0]=true;
    
    prev[arr[0]]=true;

    for (int i = 1; i < n; i++) {
        vector<bool> curr(k+1,0);
        curr[0]=true;
        for (int j = 1; j <= k; j++) {
            bool notpick =prev[j];
            bool pick = false;
            if(arr[i]<=j) pick = prev[j-arr[i]];
            curr[j] = pick|notpick;
        }
        prev = curr;
    }
    return prev[k];
}



bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
		int sum=0;
        for (int i = 0; i < n; i++) {
			sum+=arr[i];
		}
		if(sum%2!=0) return false;
		return subsetSumToK(n,sum/2,arr);
}


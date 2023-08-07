I have solved this problem using the 


#include <bits/stdc++.h>
using namespace std;
// any thing other than 0 will be treated as a true when convert it into bool while 0 will be treated as 
bool func(int i, int target, int n, vector<int> &arr, vector<vector<int>> &dp) {
    if(target==0) return true;
    if(i==0) return target==arr[0];
    if(dp[i][target]!=-1) return dp[i][target];
    bool notpick = func(i-1,target,n,arr,dp);
    bool pick = false;
    if(arr[i]<=target) pick = func(i-1,target-arr[i],n,arr,dp);
    return dp[i][target] = pick|notpick;

}
// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     // Write your code here.
//     vector<vector<bool>> dp(n,vector<bool>(k+1,0));
//     // return func(n-1, k ,n,arr,dp);
//     for (int i = 0; i < n; i++) {
//         dp[i][0]=true;
//     }
   
//     dp[0][arr[0]]=true;
//     for (int i = 1; i < n; i++) {
//         for (int j = 1; j <= k; j++) {
//             bool notpick =dp[i-1][j];
//             bool pick = false;
//             if(arr[i]<=j) pick = dp[i-1][j-arr[i]];
//             dp[i][j] = pick|notpick;
//         }
//     }
//     return dp[n-1][k];
// }


// space optimisation code is here



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


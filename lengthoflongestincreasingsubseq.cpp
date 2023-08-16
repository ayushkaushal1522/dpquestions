#include<bits/stdc++.h>
using namespace std;

// However this problem can also be solved without using dp but just maintaining the record of the number of 
// elements which are less than the current element and make an array for each and every element and then find 
// teh maximum element out of all form that array.


// And to trace back the lis also we needs to follow this method in finding out the length of the llongest 
// common subsequence.

// ->we generally do not hamper the data we have so it is preferable to contruct a new array so that it will not
// create any problme and our initial data remains intact with us only.


int func(int i, int prev, int arr[], int n , vector<vector<int>> &dp) {
    if(i==n) return 0;
    if(dp[i][prev+1]!=-1) return dp[i][prev+1];
    int len = 0 + func(i+1,prev,arr,n,dp);
    if (prev == -1 || arr[i] > arr[prev]) {
        len = max(len , 1+ func(i+1,i,arr,n,dp));
    }
    return dp[i][prev+1] = len;
}

int longestIncreasingSubsequence(int arr[], int n)
{
    // // Write Your Code here
    // vector<vector<int>> dp(n,vector<int>(n+1,0));
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for (int i = n - 1; i >= 0; i--) {
        for (int prev = i - 1; prev >= -1; prev--) {
            int len = 0 + dp[i+1][prev+1];
            if (prev == -1 || arr[i] > arr[prev]) {
                len = max(len , 1+ dp[i+1][i+1]);
            }
            dp[i][prev+1] = len;
        }
       
    }
    return dp[0][-1+1];
}
int main(){






    return 0;
}

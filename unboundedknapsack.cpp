//  it is diffrent from the 0/1 knapsack because here is the infinite supply of the objects.
#include<bits/stdc++.h>
using namespace std;

//have solved this problem using the all the three approaches the memoisation , the tabulation and finaly the space optimisation as well.


int func(int i, int w, vector<int> &value, vector<int> &weight , vector<vector<int>> &dp) {
        if (i == 0) {
            return ((int)(w/weight[0]))*value[0];
        }
        if(dp[i][w]!=-1) return dp[i][w];
        int nottake = 0 + func(i-1,w,value,weight,dp);
        int take = 0;
        if (weight[i] <= w) {
            take = value[i] + func(i,w-weight[i],value,weight,dp);
            
        }
        return dp[i][w] = max(take,nottake);
}

// int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
//     // Write Your Code Here.
//     // vector<vector<int>> dp(n,vector<int>(w+1,-1));
//     // return func(n-1,w,profit,weight,dp);
//     vector<vector<int>> dp(n,vector<int>(w+1,0));
//     for (int i = 0; i <= w; i++) {
//         dp[0][i] =  ((int)(i/weight[0]))*profit[0];
//     }
//     for (int i = 1; i < n; i++) {
//         for (int j = 0; j <= w; j++) {
//             int nottake = 0 + dp[i-1][j];
//             int take = 0;
//             if (weight[i] <= j) {
//                 take = profit[i] + dp[i][j-weight[i]];
                
//             }
//             dp[i][j] = max(take,nottake);
//             }
//     }
//     return dp[n-1][w];
// }

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    // vector<vector<int>> dp(n,vector<int>(w+1,-1));
    // return func(n-1,w,profit,weight,dp);
    vector<int> prev(w+1,0);
    for (int i = 0; i <= w; i++) {
        prev[i] =  ((int)(i/weight[0]))*profit[0];
    }
    for (int i = 1; i < n; i++) {
        vector<int> curr(w+1,0);
        for (int j = 0; j <= w; j++) {
            int nottake = 0 + prev[j];
            int take = 0;
            if (weight[i] <= j) {
                take = profit[i] +curr[j-weight[i]];
                
            }
            curr[j] = max(take,nottake);
            }
            prev = curr;
    }
    return prev[w];
}

int main(){






    return 0;
}
// in this type of problems generally greedy fails because 
// the values are not uniform in nature.

// solved the code using all three dp approaches which are first the memoisation code then the tabulation and finally the space optimisation which
// may not be necesarry for the submisiion of this particular problem.


#include <bits/stdc++.h>
int func(int i, int j, vector<vector<int>> &matrix ,int n ,int m ,vector<vector<int>> &dp){
    if(j<0 || j>=m) return -1e8;
    if(i==0) return matrix[0][j];

    if(dp[i][j]!=-1) return dp[i][j];

    int up = matrix[i][j] + func(i-1,j,matrix,n,m,dp);
    int ld = matrix[i][j] + func(i-1,j-1,matrix,n,m,dp);
    int rd = matrix[i][j] + func(i-1,j+1,matrix,n,m,dp);

    return dp[i][j] = max(up,max(ld,rd));

}
// int getMaxPathSum(vector<vector<int>> &matrix)
// {
//     //  Write your code here.
//     int n = matrix.size();
//     int m = matrix[0].size();
//     // int maxi=-1e8;
//     // vector<vector<int>> dp(n,vector<int>(m,-1));
//     // for (int i = 0; i < m; i++) {
        
//     //     maxi=max(maxi,func(n-1,i,matrix,n,m,dp));
//     // }
//     // return maxi;

//     vector<vector<int>> dp(n,vector<int>(m,0));
//     for (int i = 0; i < m; i++) {
//         dp[0][i]=matrix[0][i];
//     }
//     for (int i = 1; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             int ld=-1e8;
//             int rd=-1e8;
//             int up = matrix[i][j] + dp[i-1][j];
//             if(j>0) ld = matrix[i][j] + dp[i-1][j-1];
//             if(j<m-1) rd = matrix[i][j] + dp[i-1][j+1];

//             dp[i][j] = max(up,max(ld,rd));
//         }
//     }
//     int maxi=-1e8;
//     for (int i = 0; i < m; i++) {
        
//         maxi=max(maxi,dp[n-1][i]);
//     }
//     return maxi;
// }
    
// now it is the time for space optimisation.
int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> prev(m,0);
    for (int i = 0; i < m; i++) {
        prev[i]=matrix[0][i];
    }
    for (int i = 1; i < n; i++) {
        vector<int> curr(m,0);
        for (int j = 0; j < m; j++) {
            int ld=-1e8;
            int rd=-1e8;
            int up = matrix[i][j] + prev[j];
            if(j>0) ld = matrix[i][j] + prev[j-1];
            if(j<m-1) rd = matrix[i][j] + prev[j+1];

            curr[j] = max(up,max(ld,rd));
        }
        prev=curr;
    }
    int maxi=-1e8;
    for (int i = 0; i < m; i++) {
        
        maxi=max(maxi,prev[i]);
    }
    return maxi;
}
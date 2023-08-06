#include <bits/stdc++.h> 
// it is a thumb rule that whatever you write for a recursion just opposite of it will be there in the 
// tabulation.

// solved the minimimpath sum in a triangle in all three ways which are memoization way , then the tabulation and
// finally cleared it with the tabulation as well.


int func(int i, int j, vector<vector<int>> &triangle, int n ,vector<vector<int>> dp) {
	if(i==n-1) return triangle[n-1][j];
	if(dp[i][j]!=-1) return dp[i][j];
	int down = triangle[i][j] + func(i+1,j,triangle,n ,dp);
	int diag = triangle[i][j] + func(i+1,j+1,triangle,n , dp);
	return dp[i][j] = min(down,diag);

}

///
// int minimumPathSum(vector<vector<int>>& triangle, int n){
// 	// Write your code here.
// 	// vector<vector<int>> dp(n,vector<int>(n,-1));
// 	// return func(0,0,triangle,n,dp);

// 	vector<vector<int>> dp(n,vector<int>(n,0));
//         for (int i = 0; i < n; i++) {
// 			dp[n-1][i] = triangle[n-1][i];
//         }

//         for (int i = n - 2; i >= 0; i--) {
//             for (int j = i; j >= 0; j--) {
// 				int down = triangle[i][j] + dp[i+1][j];
// 				int diag = triangle[i][j] + dp[i+1][j+1];
// 				dp[i][j] = min(down,diag);
//             }
//         }
// 		return dp[0][0];
// }

int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	// vector<vector<int>> dp(n,vector<int>(n,-1));
	// return func(0,0,triangle,n,dp);

		vector<int> prev(n,0);
        for (int i = 0; i < n; i++) {
			prev[i] = triangle[n-1][i];
        }

        for (int i = n - 2; i >= 0; i--) {
			vector<int> curr(n,0);
            for (int j = i; j >= 0; j--) {
				int down = triangle[i][j] + prev[j];
				int diag = triangle[i][j] + prev[j+1];
				curr[j] = min(down,diag);
            }
			prev = curr;
        }
		return prev[0];
}
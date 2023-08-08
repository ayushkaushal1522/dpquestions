#include<bits/stdc++.h>
using namespace std;
int func(int i, int n, vector<int> &price,vector<vector<int>> &dp) {
  if (i == 0) {
	  return n*price[0];
  }
  if(dp[i][n]!=-1) return dp[i][n];
  int nottake = 0+func(i-1,n,price,dp);
  int take = -1e8;
  int rodlength = i+1;
  if (rodlength <= n) {
	  take  = price[i] + func(i,n-rodlength,price,dp);
  }
  return dp[i][n] = max(take,nottake);
}

// int cutRod(vector<int> &price, int n)
// {

// 	// vector<vector<int>> dp(n,vector<int>(n+1,-1));
// 	// return func(n-1,n,price,dp);
// 	// Write your code here.
// 	vector<vector<int>> dp(n,vector<int>(n+1,0));
//         for (int i = 0; i <= n; i++) {
// 			dp[0][i] = i*price[0];
//         }

//         for (int i = 1; i < n; i++) {
//                         for (int j = 0; j <= n; j++) {
// 							int nottake = 0+dp[i-1][j];
// 							int take = -1e8;
// 							int rodlength = i+1;
// 							if (rodlength <= j) {
// 								take  = price[i] + dp[i][j-rodlength];
// 							}
// 							dp[i][j] = max(take,nottake);
//                         }
//         }
// 		return dp[n-1][n];
// }

// from  here also we can more optimize itupto the limit of 1d array only.


int cutRod(vector<int> &price, int n)
{

	// vector<vector<int>> dp(n,vector<int>(n+1,-1));
	// return func(n-1,n,price,dp);
	// Write your code here.
		vector<int> prev(n+1,0);
        for (int i = 0; i <= n; i++) {
			prev[i] = i*price[0];
        }

        for (int i = 1; i < n; i++) {
			vector<int> curr(n+1,0);
                        for (int j = 0; j <= n; j++) {
							int nottake = 0+ prev[j];
							int take = -1e8;
							int rodlength = i+1;
							if (rodlength <= j) {
								take  = price[i] + curr[j-rodlength];
							}
							curr[j] = max(take,nottake);
                        }
						prev = curr;
        }
		return prev[n];
}
int main(){






    return 0;
}
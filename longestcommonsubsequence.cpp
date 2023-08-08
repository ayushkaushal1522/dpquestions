// brute force for this particular is exponential in nature.
#include<bits/stdc++.h>
using namespace std;
int func(int i, int j, string &s, string &t , vector<vector<int>> &dp) {
	if(i<0 || j<0) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	if(s[i]==t[j]) return dp[i][j] =  1 + func(i-1,j-1,s,t,dp);
	return dp[i][j] = max(func(i-1,j,s,t,dp),func(i,j-1,s,t,dp));
}
// int lcs(string s, string t)
// {
// 	//Write your code here
// 	int n=s.length();
// 	int m=t.length();
// 	// vector<vector<int>> dp(n,vector<int>(m,-1));
// 	// return func(n-1,m-1,s,t,dp);
// 	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
//         for (int i = 0; i <= m; i++) {
// 			dp[0][i] = 0;
//         }
// 		for (int i = 0; i <= n; i++) {
// 			dp[i][0] = 0;
//         }
//         for (int i = 1; i <= n; i++) {
//                         for (int j = 1; j <= m; j++) {
// 							if(s[i-1]==t[j-1]) dp[i][j] =  1 + dp[i-1][j-1];
// 							else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
//                         }
//         }
// 		return dp[n][m];
// }

int lcs(string s, string t)
{
	//Write your code here
	int n=s.length();
	int m=t.length();
	// vector<vector<int>> dp(n,vector<int>(m,-1));
	// return func(n-1,m-1,s,t,dp);
	vector<int> prev(m+1,0);
        for (int i = 0; i <= m; i++) {
			prev[i] = 0;
        }
		
        for (int i = 1; i <= n; i++) {
			vector<int> curr(m+1,0);
                        for (int j = 1; j <= m; j++) {
							if(s[i-1]==t[j-1]) curr[j] =  1 + prev[j-1];
							else curr[j] = max(prev[j],curr[j-1]);
                        }
						prev = curr;
        }
		return prev[m];
}

// using the same code we can also find out the longest common subsequence as well.

int main(){





    return 0;
}
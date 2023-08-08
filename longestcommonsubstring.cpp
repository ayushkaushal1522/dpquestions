#include<bits/stdc++.h>
using namespace std;
// this code is being derived from the code of longest commom subsequence only.
int func(string s, string t)
{
	//Write your code here
	int n=s.length();
	int m=t.length();
	// vector<vector<int>> dp(n,vector<int>(m,-1));
	// return func(n-1,m-1,s,t,dp);
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for (int i = 0; i <= m; i++) {
			dp[0][i] = 0;
        }
		for (int i = 0; i <= n; i++) {
			dp[i][0] = 0;
        }
        int ans=0;
        for (int i = 1; i <= n; i++) {
                        for (int j = 1; j <= m; j++) {
							if(s[i-1]==t[j-1]) {
                                dp[i][j] =  1 + dp[i-1][j-1];
                                ans = max(ans,dp[i][j]);
                            }
							else dp[i][j] =0;
                        }
        }
		return ans;
}

int lcs(string &str1, string &str2){
    // Write your code here.
    return func(str1 , str2);

}
// the above code can be space optimised as well , very easily.
int main(){




    return 0;
}
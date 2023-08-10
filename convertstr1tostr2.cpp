#include<bits/stdc++.h>
using namespace std;
// deletion = n - len(lcs)
// insertion = m - len(lcs) 
// total -> m+n-2*len(lcs());

// from here it  can be space optimised also.

int lcs(string s, string t)
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
        for (int i = 1; i <= n; i++) {
                        for (int j = 1; j <= m; j++) {
							if(s[i-1]==t[j-1]) dp[i][j] =  1 + dp[i-1][j-1];
							else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                        }
        }
		return dp[n][m];
}



int canYouMake(string &s1, string &s2){
    // Write your code here.
    int n = s1.length();
    int m = s2.length();
    int ans  = n + m - (2*lcs(s1,s2));
    return ans;
}
int main(){

    


    return 0;
}

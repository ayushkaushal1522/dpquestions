#include<bits/stdc++.h>
using namespace std;
// if there vare overlapping subproblems then we are tend to apply the memoization.
// in that particular question.


// a simple memoization code which just go up and the left.
// time complexity for this is given by O(n*m) as it  ahve to try for all the cells.
// and the space mcomplexity is given by O(n-1 + m-1) + O(n*m).
// the first one is the recursion stack space and the next one is the 2d array that we are using.

int func(int i, int j ,vector<vector<int>> &dp) {
	if(i==0 && j==0) return 1;
	if(i<0 || j<0) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	int left = func(i,j-1,dp);
	int up= func(i-1,j,dp);
	return dp[i][j] = left+up;
}

// here is the tabulated code which we all should know to be.
// now also furthur space optimisation is possible that we can do here to get out the best code by reducing the space complexity.

int uniquePaths(int m, int n) {
	// Write your code here.
	vector<vector<int>> dp(n,vector<int>(m,0));
	    dp[0][0]=1;
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
			if(i==0 && j==0) dp[i][j]=1;
            else{
				int left=0;
				int up=0;
				if(j>0) left = dp[i][j-1];
				if(i>0) up= dp[i-1][j];
				dp[i][j] = left+up;
            }
          }
        }
		return dp[n-1][m-1];
}


// so in this way we can space optimize also as we can easily see the only role of prev and curr row in the finding out the value of the current cells
// so what there is need of carrying the whole 2d array dp.

int uniquePaths(int m, int n) {
	// Write your code here.
	vector<int> prev(m,0);
    
        for (int i = 0; i < n; i++) {
            vector<int> curr(m,0);
            for (int j = 0; j < m; j++) {
                if(i==0 && j==0) curr[0]=1;
                else{
                    int left=0;
                    int up=0;
                    if(j>0) left = curr[j-1];
                    if(i>0) up= prev[j];
                    curr[j] = left+up;
                }
            }
            prev=curr;
        }
		return prev[m-1];
}


int main(){

    //for the tabulation code the time complexity is given by O(n*m)
    //and the space complexity is given by O(n*m) as well.
    




    return 0;
}
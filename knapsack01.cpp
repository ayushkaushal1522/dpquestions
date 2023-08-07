#include <bits/stdc++.h> 
using namespace std;
//All the combinations can be taken into the consideration just by using the recursion only there is no other way possible.
//try to think about the base case as a single element always.

int func(int i, int w, vector<int> &weight, vector<int> &value,vector<vector<int>> &dp) {
	if(i==0){
		if(weight[0]<=w) return value[0];
		else return 0;
	}
	if(dp[i][w]!=-1) return dp[i][w];
	int nottake = 0 +func(i-1 ,w ,weight ,value,dp);
	int take =INT_MIN;
	if(weight[i]<=w) take = value[i]+ func(i-1,w-weight[i],weight ,value,dp);
	return dp[i][w] = max(nottake , take);
}
// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
// {
// 	// Write your code here
// 	vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
// 	// return func(n-1 , maxWeight , weight , value ,dp);
//         for (int i = weight[0]; i <= maxWeight; i++) {
// 			dp[0][i] = value[0];
// 		}

//         for (int i = 1; i < n; i++) {
//                         for (int j = 0; j <= maxWeight; j++) {
//                           int nottake = 0 + dp[i - 1][j];
//                           int take = INT_MIN;
//                           if(weight[i] <= j) take = value[i]+ dp[i-1][j-weight[i]];
//                           dp[i][j] = max(nottake, take);
//                         }
//         }
//         return dp[n - 1][maxWeight];

// }



// from here also we can more space optimize it  to a one array as well so keep this thing in mind as it is
// one of the important thing.

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<int> prev(maxWeight+1,0);
	// return func(n-1 , maxWeight , weight , value ,dp);
        for (int i = weight[0]; i <= maxWeight; i++) {
			prev[i] = value[0];
		}

        for (int i = 1; i < n; i++) {
				vector<int> curr(maxWeight+1,0);
                        for (int j = 0; j <= maxWeight; j++) {
                          int nottake = 0 + prev[j];
                          int take = INT_MIN;
                          if(weight[i] <= j) take = value[i]+ prev[j-weight[i]];
                          curr[j] = max(nottake, take);
                        }
						prev= curr;
        }
        return prev[maxWeight];

}
int main(){


    return 0;
}
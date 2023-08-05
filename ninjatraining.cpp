#include<bits/stdc++.h>
using namespace std;

// if there is any line about the previous row or the previous column then 
// that means we can easily apply space optimisation there.



int func(int day , int last , vector<vector<int>> &points, vector<vector<int>> &dp){
    if(day==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                maxi=max(maxi,points[0][i]);
            }
        }
        return maxi;
    }
    if(dp[day][last] != -1) return dp[day][last];

    int maxi=0;
    for(int i=0;i<3;i++){
        if(i!=last){
            int point = points[day][i]+func(day-1,i,points,dp);
            maxi=max(maxi,point);
        }
    }
    return dp[day][last] = maxi;
}

// tabulated code
// time complexity for this is given by O(n*4*3).
// space complexity is given by O(n*4)
// can space optimize also it furthur.

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(4,0));
    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] = max(points[0][0],points[0][2]);
    dp[0][2] = max(points[0][0],points[0][1]);
    dp[0][3] = max(points[0][0],max(points[0][1],points[0][2]));

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= 3; j++) {
            int maxi=0;
            for(int k=0;k<3;k++){
              if (k != j) {
                int point = points[i][k] + dp[i - 1][k];
                maxi = max(maxi, point);
              }
            }
            dp[i][j] = maxi;
        }
    }
    return dp[n-1][3];
    
    
}

int main(){


    int n;
    cin>>n;
    


    return 0;
}
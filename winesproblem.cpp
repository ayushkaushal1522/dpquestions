#include<bits/stdc++.h>
using namespace std;


int func(int wines[] ,int i , int j , int y , vector<vector<int>> &dp){

    if(i>j) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int op1 = wines[i]*y + func(wines , i+1 , j , y+1,dp);
    int op2 = wines[j]*y + func(wines , i, j-1 , y+1,dp);
    return dp[i][j] = max(op1,op2);




}


int main(){



    int wines[] = {2,3,5,1,4};
    int n = sizeof(wines)/sizeof(int);
    int y=1;
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout<<func(wines,0,n-1,y , dp)<<endl;




    return 0;
}

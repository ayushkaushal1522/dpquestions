// try to figure out for recursion and then you can go for memoization and then go for tabulatioj as well.
//this problem is exact similar to that of the fibonacci sequence.

#include<bits/stdc++.h>
using namespace std;

// time complexity is given by O(n)
int func(int n,vector<int> &dp){
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n] = func(n-1,dp)+func(n-2,dp);
}


int main(){



    int n;
    cin>>n;
    // vector<int> dp(n+1,-1);
    // cout<<func(n,dp)<<endl;


    // for this time complexity is O(n) and space complexity is given by O(n) only.

    vector<int> dp(n+1);
    dp[0]=0;
    dp[1]=1;

    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }

    cout<<dp[n]<<endl;



    return 0;
}

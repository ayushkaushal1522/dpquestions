#include<bits/stdc++.h>
using namespace std;
//whenveer you are solving the dp question it is prefered not to think 
// about solving the whole problem but the current one only by using the 
// output of the previous one.

//Now I can say that i have the ability and capability to convert a 
// memoisation code into the dp code.

//we can more space optimize it as there is a need of last k elements only so 
// k size array is sufficient and there is no need to maintain 
// the array of size n (where n is the number of elements)

//Hence we can also eliminate one loop also and bring thatg whole work 
// in O(1) only.
int func(int n , int k , vector<int> &dp){
    if(n==0) return 1;
    if(dp[n]!=-1) return dp[n];
    int ways = 0 ;
    for(int i=1;i<=k;i++){
        if(n-i>=0) ways+= func(n-i, k, dp);
    }
    return dp[n] = ways;
}

int func_bottomup(int n, int k){
    vector<int> dp(100,0);
    dp[0]=1;
    for(int j=1;j<=n;j++){
        int ways = 0 ;
        for(int i=1;i<=k;i++){
            if(j-i>=0) ways+= dp[j-i];
        }
        dp[j] = ways;
    }
    return dp[n];
    // for(int  j=1;j<=n;j++){
    //     dp[j]=0;
    //     for(int i=1;i<=k;i++){
    //         if(j-i>=0) dp[j]+= dp[j-i];
    //     }
    //     // dp[j] = ways;
    // }
    // return dp[n];

}


int main(){



    int n,k;
    cin>>n>>k;
    vector<int> dp(n+1,-1);
    // cout<<func(n,k,dp)<<endl;
    cout<<func_bottomup(n,k)<<endl;




    return 0;
}
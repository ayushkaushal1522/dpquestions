#include<bits/stdc++.h>
using namespace std;

int func(int ind,vector<int> &arr , vector<int> &dp){
    if(ind==0) return arr[0];
    if(ind<0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    
    int pick = arr[ind]+func(ind-2,arr ,dp);
    int notpick = 0 + func(ind-1 , arr ,dp);
    return dp[ind] = max(pick , notpick);
}
int main(){


    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> dp(n,-1);
    
    // cout<<func(n-1 , arr, dp)<<endl;

    // dp[0]=arr[0];
    // for(int i=1;i<n;i++){
    //     int pick =INT_MIN;
    //     int notpick = INT_MIN;
    //     if((i-2)>=0){
    //         pick = arr[i]+func(i-2,arr ,dp);
    //     }
    //     if((i-1)>=0){
    //         notpick = 0 + func(i-1 , arr ,dp);
    //     }
    //     dp[i] = max(pick , notpick);
    // }
    // cout<<dp[n-1]<<endl;

    // here is the thing to observe is that for calculating dp[i] we just need 
    // dp[i-1] and dp[i-2].


    // hence the final and optimize code have the tc of o(n) ans space coplexity 
    // of just O(1).
    int prev2=0;
    int prev1=arr[0];
    for(int i=1;i<n;i++){
        int pick =INT_MIN;
        int notpick = INT_MIN;
        
        if((i-2)>=0){
            pick = arr[i]+prev2;
        }
        if((i-1)>=0){
            notpick = 0 + prev1;
        }
        int curr = max(pick , notpick);
        prev2 = prev1;
        prev1 = curr;
       
    }
    cout<<prev1<<endl;



    return 0;
}
#include<bits/stdc++.h>
using namespace std;


int frogjump(int i , vector<int> &arr,vector<int> &dp,int k){
        if(i==0) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int mini=INT_MAX;
        for(int j=1;j<=k;j++)
        {   int jump =INT_MAX;
            if((i-j)>=0){
                jump = frogjump(i-j,arr,dp,k)+abs(arr[i]-arr[i-j]);
            }
            mini = min(mini,jump);
        }
        return dp[i] = mini;
        
        

    }


int main(){
    
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int steps;
    cin>>steps;
    vector<int> dp(n,-1);
    // cout<<frogjump(n-1,arr,dp,steps)<<endl;
    dp[0]=0;
    // for(int i=1;i<n;i++){
    //      int mini=INT_MAX;
    //     for(int j=1;j<=steps;j++)
    //     {   int jump =INT_MAX;
    //         if((i-j)>=0){
    //             jump = dp[i-j]+abs(arr[i]-arr[i-j]);
    //         }
    //         mini = min(mini,jump);
    //     }
    //     dp[i] = mini;
    // }


    cout<<dp[n-1]<<endl;
    return 0;
}
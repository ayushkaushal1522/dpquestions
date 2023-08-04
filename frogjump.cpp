 #include<bits/stdc++.h>
 using namespace std;

    int frogjump(int i , vector<int> &arr,vector<int> &dp){
        if(i==0) return 0;
        if(dp[i]!=-1) return dp[i];
        int left = frogjump(i-1,arr,dp)+abs(arr[i]-arr[i-1]);
        int right = INT_MAX;
        if(i>=2){
            right = frogjump(i-2 , arr,dp)+abs(arr[i]-arr[i-2]);
        }
        return dp[i]= min(left ,right);
        

    }


 int main(){


    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> dp(n+1,-1);
    cout<<frogjump(n-1,arr,dp)<<endl;




    return 0;
 }
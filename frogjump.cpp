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
    vector<int> dp(n,-1);
    cout<<frogjump(n-1,arr,dp)<<endl;
    // dp[0]=0;
    
    // for(int i=1;i<n;i++){
    //     int l = dp[i-1]+abs(arr[i]-arr[i-1]);
    //     int r = INT_MAX;
    //     if(i>=2){
    //         r = dp[i-2]+abs(arr[i]-arr[i-2]);
    //     }
    //     dp[i]  = min(l,r);

    // }
    // cout<<dp[n-1]<<endl;

    //more we can space optimize it also as really there is no need to contein a dp array.
    //if there are k jumps to be taken then that can also be easily solved 
    // using the for loop but we can not space optimize it furthur to O(1) however we can upto O(k).





    return 0;
 }
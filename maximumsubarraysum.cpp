// this questions can be solved by finding the cumulative sum ans then by checking 
// for each and every pair the sum that what is the sujm and after that take minimu of 
// all of that.
//However the time complexity of this code is given by O(n^2).
//we can optimize the same using the dp approach.
#include<bits/stdc++.h>
using namespace std;
int maxisum(int a[] , int n){
    //however here is no need to maintain an array of dp containing 
    // the info about all state that is we can space optimize this problem\
    // here very easily.
    int dp[100] = {0};
    dp[0] = a[0]>0?a[0]:0;
    int maxi = a[0];
    for(int i=1;i<n;i++){
        dp[i] = dp[i-1] + a[i];
        if(dp[i]<0) dp[i]=0;
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}

int maxisumspace(int a[] , int n){
    //however here is no need to maintain an array of dp containing 
    // the info about all state that is we can space optimize this problem\
    // here very easily.
    int prevsum = a[0]>0?a[0]:0;
    // int currsum = 0;
    int maxi = a[0];
    for(int i=1;i<n;i++){
        int currsum = prevsum + a[i];
        if(currsum<0) currsum=0;
        maxi = max(maxi, currsum);
        prevsum = currsum;
    }
    return maxi;
}
int main(){


    int arr[] = {-3,2,5,-1,6,3,-2,7,-5,2};
    int n = sizeof(arr)/sizeof(int);
    // cout<<maxisum(arr,n)<<endl;
    cout<<maxisumspace(arr,n)<<endl;
    //It is the most optimized code that we can write in oredr to improve the 
    // way and alos we can measure it by finding out the ktime and space 
    // complexity for the same.

    // This code however fails in case of all negative elements however we can handle that case bby finding out the 
    // maximum negative element in the whole array and just output that only.




    return 0;
}

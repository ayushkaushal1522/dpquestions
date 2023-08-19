#include<bits/stdc++.h>
using namespace std;


//dhyaan se obserevr karo it is easy to find out the pattern in the answer of thi stype of respective question.

int ladder_optimize(int n ,int k){
    int dp[100] = {0};
    dp[0]=dp[1]=1;
    for(int i=2;i<=k;i++){
        dp[i] = 2*dp[i-1]; 
        //jab tak k elements reach he nahi kare hein tab tak toh jo hai
        // kewal 2*dp[i-1] he karna padega na.
        //that is only the main intution and the best solution possible for this
        // particular problem as the time complexity for this particular is 
        // given by O(n).



    }
    for(int i=k+1;i<=n;i++){
        dp[i] = 2*dp[i-1] - dp[i-k-1];
    }

    return dp[n];

}
int main(){

    int n,k;
    cin>>n>>k;
    cout<<"Bottom Up ways are "<<ladder_optimize(n,k)<<endl;

    return 0;
}
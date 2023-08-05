#include<bits/stdc++.h>
using namespace std;
// Almost same code as that of the maximum sum of the non-adjacent elements.
//this is the space optimized code of teh above said problem.
int func(vector<int> &arr){
    int n=arr.size();
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
    return prev1;
}
int main(){

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(arr.size()==1) {cout<<arr[0]<<endl;return 0;}
    vector<int> temp1,temp2;
    for(int i=0;i<n;i++){
        if(i!=0){
            temp1.push_back(arr[i]);
        }
        if(i!=n-1){
            temp2.push_back(arr[i]);
        }
    }
    int finalans = max(func(temp1),func(temp2));
    cout<<finalans<<endl;
    





    return 0;
}
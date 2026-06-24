class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
          int n=arr.size();
       vector<int>dp(n,INT_MAX);
       dp[0]=0;
       for(int i=0;i<n;i++){
           if(dp[i]==INT_MAX)return -1;
           dp[min(n-1,i+arr[i])]=min(dp[i]+1,dp[min(n-1,i+arr[i])]);
           int j=min(n-1,i+arr[i])-1;
           while(j>i && dp[j]==INT_MAX){
               dp[j]=dp[min(n-1,i+arr[i])];
               j--;
           }
       }
       return dp[n-1];
        
    }
};

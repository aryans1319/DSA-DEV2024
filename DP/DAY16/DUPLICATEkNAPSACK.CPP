//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
private:
    int solve(int W, int i, int wt[], int val[],vector<vector<int>>&dp){
        
        if(i==0){
            if(wt[i]<=W){
                return val[i]*(W/wt[i]);
            }
            return 0;
        }
        
        if(dp[i][W]!=-1) return dp[i][W];
        
        int pick = 0;
        if(wt[i]<=W){
            pick = val[i] + solve(W-wt[i],i,wt,val,dp);
        }
        
        int notPick = solve(W,i-1,wt,val,dp);
        
        return dp[i][W]=max(pick,notPick);
        
    }
    
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
        
        return solve(W,N-1,wt,val,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends
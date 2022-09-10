#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int solve(int index, int target, vector<vector<int>>&dp){
        
        if(index == 0 || target==0){
            return 1;
        }
        
        if(dp[index][target]!=-1)
            return dp[index][target];
        
        int notTake = solve(index-1,target,dp);
        int curr = index;
        
        int take = INT_MIN;
        
        if(curr <= target)
            take = curr * solve(index,target-curr,dp);
        
        return dp[index][target] = max(notTake, take);
        
        
    }
    
    int integerBreak(int n) {
        
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(n-1,n,dp);
    }
};

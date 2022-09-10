#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(int index, int target, vector<vector<int>>&dp){
        if(target==0) return 1;
        if(index <= 0 ){
            
            return INT_MAX;
        }
        
        if(dp[index][target]!=-1)
            return dp[index][target];
        
        int notTake = solve(index-1,target,dp);
        int curr = index*index;
        
        int take = INT_MAX;
        
        if(curr <= target ) 
            take = 1+solve(index,target-curr,dp);
        
        return dp[index][target] = min(take,notTake);
        
        
    }
public:
    int numSquares(int n) {
        if(n<4) return n;
        int sq=sqrt(n);
        vector<vector<int>>dp(sq+1,vector<int>(n+1,-1));
        return solve(sq,n,dp)-1;
    }
};
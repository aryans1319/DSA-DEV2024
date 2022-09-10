#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int solve(int ind,vector<int>&coins,int amount,vector<vector<int>>&dp){   
        if(ind==0){
            if(amount%coins[ind]==0) return amount/coins[ind];
            return 1e9;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int pick=INT_MAX;
        if(amount>=coins[ind]){
            pick=1+solve(ind,coins,amount-coins[ind],dp);
        }
        int notPick=solve(ind-1,coins,amount,dp);

        return  dp[ind][amount]=min(pick,notPick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if(amount==0)return 0;
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        
        return solve(n-1,coins,amount,dp);
    }
};
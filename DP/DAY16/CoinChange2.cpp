#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int ind,vector<int>&coins,int amount,vector<vector<int>>&dp){   
        if(ind==0){
            if(amount%coins[ind]==0) return 1;
            return 0;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int pick=0;
        if(amount>=coins[ind]){
            pick=solve(ind,coins,amount-coins[ind],dp);
        }
        int notPick=solve(ind-1,coins,amount,dp);

        return  dp[ind][amount]=(pick+notPick);
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        if(amount==0)return 1;
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return (solve(n-1,coins,amount,dp));
        
        

    }
};
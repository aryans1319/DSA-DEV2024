### 1.  Coin Change (LeetCode)

```
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

```
### 2.  Coin Change II (LeetCode)
```

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
```
### 3. Duplicate Knapsack(GFG)
```
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
```
### 4. Combination Sum IV (LeetCode)

```
class Solution {
public:
    int cal(vector<int>&nums,int target, vector<int>&dp){
        if(target==0) return 1;
        if(target<0) return 0;
        
        if(dp[target]!=-1) return dp[target];
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=target) count+=cal(nums,target-nums[i],dp);
        }
        return dp[target]=count;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<int>dp(target+1,-1);
        return cal(nums,target,dp);
    }
};
```
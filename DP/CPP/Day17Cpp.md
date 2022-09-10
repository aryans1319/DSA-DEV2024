### 1.  Rod Cutting 

```
class Solution{
private:
    int solve(int price[],int index,int length,vector<vector<int>>&dp){
        
        if(index==0){
            return price[0]*length;
        }
        if(dp[index][length]!=-1) return dp[index][length];
        
        int notTake = solve(price,index-1,length,dp);
        int rodLength=index+1;
        int take=INT_MIN;
        if(length>=rodLength){
            take=price[index] + solve(price,index,length-rodLength,dp);
        }
        
        return dp[index][length]=max(take,notTake);
        
    }
  public:
    int cutRod(int price[], int n) {
        
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        
        // n-1 is the index, n is the length of the rod
        return solve(price,n-1,n,dp);
    }
};

```
### 2.  Integer Break
```

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
```
### 3. Perfect Squares
```
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
```

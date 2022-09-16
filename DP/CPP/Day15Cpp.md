### 1. Maximum Path Sum in the matrix (CN)
Memoization
```
int solve(vector<vector<int>> &matrix,vector<vector<int>> &dp,int i,int j){
    if(j<0 || j>=matrix[i].size()) return -1e9;
    
    if(i==0) return matrix[i][j];
    
    if(dp[i][j]!=-1) return dp[i][j];
    int up=matrix[i][j]+solve(matrix,dp,i-1,j);
    int leftDiag=matrix[i][j]+solve(matrix,dp,i-1,j-1);
    int rightDiag=matrix[i][j]+solve(matrix,dp,i-1,j+1);
    
    return dp[i][j] = max(up,max(leftDiag,rightDiag));
        
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
vector<vector<int>> dp(n,vector<int>(m,-1));
    int maxi=INT_MIN;
     for(int j=0;j<m;j++){
         int ans=solve(matrix,dp,n-1,j);
         maxi=max(ans,maxi);
     }
}
```
Tabulation
```
int getMaxPathSum(vector<vector<int>> &matrix)
{
     int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));

    for(int j=0; j<m; j++){
        dp[0][j] = matrix[0][j];
    }
    
    for(int i=1; i<n; i++){
        for(int j=0;j<m;j++){
            
            int up = matrix[i][j] + dp[i-1][j];
            
            int leftDiagonal= 0;
            if(j-1>=0) leftDiagonal = matrix[i][j]+ dp[i-1][j-1];
            else leftDiagonal += -1e9;
            
            int rightDiagonal =0;
            if(j+1<m) rightDiagonal = matrix[i][j]+ dp[i-1][j+1];
            else rightDiagonal += -1e9;
            
            dp[i][j] = max(up, max(leftDiagonal,rightDiagonal));
            
        }
    }
    
    int maxi = dp[n-1][0];
    
    for(int j=1; j<m;j++){
        maxi = max(maxi,dp[n-1][j]);
    }
    
    return maxi;
}

```
### 2. Maximal Square (LC)

Memoization
```
class Solution {
private:
    
    int maxi=0;

    int solve(vector<vector<char>>&m,int i, int j,vector<vector<int>>&dp){
        
        if(i>=m.size() || j>=m[0].size()) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];

        int right=solve(m,i,j+1,dp);
        int diag=solve(m,i+1,j+1,dp);
        int bottom=solve(m,i+1,j,dp);

        if(m[i][j]=='1')
        {
            dp[i][j]=1+min(right,min(diag,bottom));
            maxi=max(maxi,dp[i][j]);
            
            return dp[i][j];
        }
        else 
        {
            return 0;
        }
        
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        solve(matrix,0,0,dp);
        return maxi*maxi;
    }
};
```


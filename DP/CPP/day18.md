***1. LCS (Longest Common Subsequence)***


```
Memoization

class Solution {
public:
    int lcs(string s, string t, int ind1, int ind2,vector<vector<int>>&dp){
        if(ind1 == 0 || ind2 == 0){
            return 0;
        }
        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }
        if(s[ind1-1] == t[ind2-1]){
            return dp[ind1][ind2] = 1 + lcs(s, t, ind1 - 1, ind2 - 1,dp);
        }
        
        return dp[ind1][ind2] = max(lcs(s,t,ind1-1,ind2,dp), lcs(s,t,ind1, ind2-1,dp));
    }
    
    int longestCommonSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n+1 , vector<int>(m+1,-1));
        return lcs(s, t, n, m,dp);
        
    }
};

Bottom up

class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n+1 , vector<int>(m+1,-1));
        
        for(int j = 0; j<=m; j++) dp[0][j] = 0;
        for(int i = 0; i<=n; i++) dp[i][0] = 0;
        
        for(int i=1; i<=n; i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[n][m];
        
    }
};
```

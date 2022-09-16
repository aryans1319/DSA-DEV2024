### 1.  Longest Common Substring (GFG)
Memoization

```
class Solution{
    int maxAns=0;

    public:
    int solve(string &s1, string &s2,int ind1,int ind2,vector<vector<int>>&dp){
        
        if(ind1<0 || ind2<0) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        int maxi=0;
        if(s1[ind1]==s2[ind2]){
            
            maxi=1+ solve(s1,s2,ind1-1,ind2-1,dp);
            maxAns=max(maxAns,maxi);
            
        }
        
        return dp[ind1][ind2]=maxi;        
    }
    public:    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        vector<vector<int>>dp(n,vector<int>(m,-1));
        // solve(S1,S2,n-1,m-1,dp);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                solve(S1,S2,i,j,dp);
            }
        }
        return maxAns;
    }
};
```
Tabulation
```
Class Solution {

public:
    int longestCommonSubstr (string S1, string S2, int n, int m){
        int dp[n + 1][m + 1];
        for(int i = 0; i < n; i++){
            dp[i][0] = 0;
        }
        for(int j = 0; j < m; j++){
            dp[0][j] = 0;
        }
        int ans = 0;
        for(int i = 1; i  <= n; i++){
            for(int j = 1; j <= m; j++){
            if(S1[i - 1] == S2[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(dp[i][j], ans);
            } 
            else{
                dp[i][j] = 0;
            }
            }
        }
        return ans;
    }
};
```
### 2.  Minimum Insertion Steps to Make a String Palindrome(LeetCode)

Memoization
```
class Solution {
public:
int solve(int i,int j,string& s1,string& s2,vector<vector<int>>& dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j]){
        return dp[i][j]=1+solve(i-1,j-1,s1,s2,dp);
    }
    else{
        return dp[i][j]=max(solve(i-1,j,s1,s2,dp),solve(i,j-1,s1,s2,dp));
    }
}

int minInsertions(string s) {
    string s2=s;
    reverse(s2.begin(),s2.end());
    vector<vector<int>> dp(s.size(),vector<int> (s.size(),-1));
    return s.size()-solve(s.size()-1,s2.size()-1,s,s2,dp);
    }    
};

```
Tabulation
```
class Solution {
public:
    
    int longestPalindromeSubseq(string s1) {
        string s2=s1;
        reverse(s2.begin(),s2.end());
        
        int n=s1.size();
        int m=s2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int j=0;j<=m;j++){
            dp[0][j]=0;
        }
        
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
       
        for(int i=1;i<=n;i++){
           for(int j=1;j<=m;j++){
             if(s1[i-1]==s2[j-1]){
                 dp[i][j]=1+ dp[i-1][j-1];
                 
             }else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }    
        return dp[n][m];
    }

    int minInsertions(string s) {
        return s.size()-longestPalindromeSubseq(s);
    }
};
```
### 3.  Delete Operation for Two Strings(LeetCode)
Memoization
```
class Solution {
public:
    int LCS(string word1,int i,string word2, int j,vector<vector<int>>&dp){
        
        if(i<0 || j<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) return dp[i][j]= 1+LCS(word1,i-1,word2,j-1,dp);
        
        int match=LCS(word1,i-1,word2,j,dp);
        int notMatch=LCS(word1,i,word2,j-1,dp);
        
        return dp[i][j]=max(match,notMatch);
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int lcs= LCS(word1,word1.size()-1,word2,word2.size()-1,dp);
        // cout<<lcs<<endl;
        return (word1.size()+word2.size())-2*lcs;
    }
};
```
Tabulation
```
class Solution {
public:
int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int j=0;j<=m;j++){
            dp[0][j]=0;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=1;i<=n;i++){
           for(int j=1;j<=m;j++){
             if(word1[i-1]==word2[j-1]) dp[i][j]=1+ dp[i-1][j-1];
              else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return (word1.size()+word2.size())-2*dp[n][m];
    }

};
```
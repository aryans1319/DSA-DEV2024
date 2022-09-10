```
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

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

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
```

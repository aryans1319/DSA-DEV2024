### 1. BFS

```

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
        int visited[V]={0};
        
        visited[0]=1;// mark as true since its initially inserted in q
        
        queue<int>store;
        
        store.push(0); // zero based indexing
        
        vector<int>ans;
        
        while(!store.empty()){
        
            int node = store.front();
        
            store.pop();
            
            ans.push_back(node);
            
            for(auto it: adj[node]){
                if(!visited[it]){
                    visited[it]=1;
                    store.push(it);
                }
            }
        }
        return ans;
        
    }
};

```
### 2. DFS

```
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs) {
        
        storeDfs.push_back(node); 
        
        for(auto it : adj[node]) {
            if(!vis[it]) {
                vis[it] = 1; 
                dfs(it, vis, adj, storeDfs); 
            }
        } 
    }
public:
	vector<int>dfsOfGraph(int V, vector<int> adj[]){
	    vector<int> storeDfs; 
	    vector<int> vis(V, 0); 
        vis[0]=1;
        dfs(0, vis, adj, storeDfs); 
	    return storeDfs; 
	}
};

```
### 3. Number of Provinces

DFS ->
```
class Solution {
public:
  void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs) {
        
       storeDfs.push_back(node); 
       vis[node] = 1; 

        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, vis, adj, storeDfs); 
            }
        }   
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        
        vector<int>adj[n];
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j]!=0){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>ans;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                cnt++;
               dfs(i,vis,adj,ans);
            }
        }
        return cnt;        
    }
};
```
BFS->
```
class Solution {
public:
int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        
        vector<int>adj[n];
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j]!=0){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>ans;
        int cnt=0;
        for(int i=0;i<n;i++){
            
            if(vis[i])continue;

           cnt++;
        
            vis[0]=1;

            queue<int>store;

            store.push(i); 

            vector<int>ans;

            while(!store.empty()){

                int node = store.front();

                store.pop();

                ans.push_back(node);

                for(auto it: adj[node]){
                    if(!vis[it]){
                        vis[it]=1;
                        store.push(it);
                    }
                }
            }
        }
        return cnt;        
    }
};
```
### 1. Max Area of Island

DFS-->

```
class Solution {
private:
    int dfs(int i, int j, vector<vector<int>>&grid){
        
        if(i < 0 || i>=grid.size() || j>=grid[0].size() || j<0 || grid[i][j]==0) return 0;
        
        grid[i][j]=0;
        
        return 1 + dfs(i+1,j,grid) + dfs(i-1,j,grid) + dfs(i,j+1,grid) + dfs(i,j-1,grid);
         
        
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int maxi = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    maxi = max(maxi,dfs(i,j,grid));                
                }
            }
        }
        return maxi;
    }
};
```

### 2. Key and Rooms

DFS-->

```
class Solution {
public:
    void dfs(vector<vector<int>>& rooms,vector<bool>&vis,int ind){
        vis[ind]=1;
        for(auto room:rooms[ind]){
            if(!vis[room])
                dfs(rooms,vis,room);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>vis(n,false);
        dfs(rooms,vis,0);
        for(auto v : vis) if(!v) return false; 
	    return true;
    }
};

```
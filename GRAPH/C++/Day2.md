### 1. Number of Islands

```
class Solution {
public:
    bool isValid(int i,int j,vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]=='1') return true;
        return false;
    }
    
    void dfs(int i,int j,vector<vector<char>>& grid){
        
        grid[i][j]='0';
        if(isValid(i-1,j,grid)){
            dfs(i-1,j,grid);
        }
        if(isValid(i+1,j,grid)){
            dfs(i+1,j,grid);
            
        }
        if(isValid(i,j-1,grid)){
            dfs(i,j-1,grid);
            
        }
        if(isValid(i,j+1,grid)){
            dfs(i,j+1,grid);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
    
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
        
        return ans;
    }
};
```
### 2. Flood Fill

```
class Solution {
public:
    bool isValid(int i,int j,vector<vector<int>>& grid,int match){
        int n=grid.size();
        int m=grid[0].size();
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]==match){
                  
            return true;
        } 
        return false;
    }
    void dfs(int i,int j,vector<vector<int>>& grid,int match,int color){
        
        
        grid[i][j]=color;
                    
        if(isValid(i-1,j,grid,match)){
            dfs(i-1,j,grid,match,color); 
        }
        if(isValid(i+1,j,grid,match)){
            dfs(i+1,j,grid,match,color);            
        }
        if(isValid(i,j-1,grid,match)){
            dfs(i,j-1,grid,match,color);
        }
        if(isValid(i,j+1,grid,match)){
            dfs(i,j+1,grid,match,color);
        }

    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int match=image[sr][sc];
        if(color==match) return image;
        dfs(sr,sc,image,match,color);
        return image;
        
    }
    
};

```

### 3. Number of Closed Islands

```
class Solution {
    
public:
    
    bool isValid(int i,int j,vector<vector<int>>& grid){
        
        int n=grid.size();
        
        int m=grid[0].size();
        
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]==0) return true;
        
        return false;
        
    }
    
    void dfs(int i,int j,vector<vector<int>>& grid){

        grid[i][j]=1;
        
        if(isValid(i-1,j,grid)){

            dfs(i-1,j,grid);
            
        }
        
        if(isValid(i+1,j,grid)){
            
            dfs(i+1,j,grid);
            
        }
        
        if(isValid(i,j-1,grid)){
            
            dfs(i,j-1,grid);
            
        }
        
        if(isValid(i,j+1,grid)){
            
            dfs(i,j+1,grid);
            
        }
        
    }
    
public:
    
    int closedIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<n;i++){
            if(grid[i][0]==0) dfs(i,0,grid);
        }           
     
        for(int i=0;i<m;i++){
            if(grid[0][i]==0) dfs(0,i,grid);
        }
            
        for(int i=0;i<n;i++){
            if(grid[i][m-1]==0) dfs(i,m-1,grid);
        }     

        for(int i=0;i<m;i++){
            if(grid[n-1][i]==0) dfs(n-1,i,grid);
        }          
        
        int cnt=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0) {
                    cnt++;
                    dfs(i,j,grid);
                }
            }
        }
        return cnt;        
    }
};
```
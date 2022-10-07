## 1. BFS of Graph

```
class Solution {
    // Function to return Breadth First Traversal of given graph.
    public ArrayList<Integer> bfsOfGraph(int V, ArrayList<ArrayList<Integer>> adj) {
        // Code here
        ArrayList<Integer> bfs = new ArrayList<Integer>();
        boolean vis[] = new boolean[V];
        Queue<Integer> q = new LinkedList<>();
        
        q.add(0);
        vis[0] = true;
        
        while(!q.isEmpty()){
            Integer node = q.poll();
            bfs.add(node);
            
            for(Integer it : adj.get(node)){
                if(!vis[it]){
                    vis[it] = true;
                    q.add(it);
                }
            }
        }
        return bfs;
    }
}
```

## 2. DFS of Graph

```
public class DfsGraph {
    public void dfsRecursive(int node, ArrayList<ArrayList<Integer>> adj, boolean[] vis, ArrayList<Integer> list){
        vis[node] = true;
        list.add(node);
        
        for(int neighbour : adj.get(node)){
            if(!vis[neighbour]){
                vis[neighbour] = true;
                dfsRecursive(neighbour, adj, vis, list);
            }
        }
    }
    public ArrayList<Integer> dfsOfGraph(int V, ArrayList<ArrayList<Integer>> adj) {
        // Code here
        boolean vis[] = new boolean[V+1];
        vis[0] =true;
        ArrayList<Integer> list = new ArrayList<Integer>();
        dfsRecursive(0, adj, vis, list);
        return list;
    }
}
```

## Number of Provinces

```
public class NumberofProvinces {

    // DFS
    public void dfs(int node, int[][] isConnected, boolean vis[]){
        vis[node] = true;
        for(int j = 0; j < isConnected.length;j++){
            if(!vis[j] && isConnected[node][j] == 1){
                vis[j] = true;
                dfs(j, isConnected,vis);
            }
        }
    }
    public int findCircleNum(int[][] isConnected) {
        
        boolean vis[] = new boolean[isConnected.length];
        int count = 0;
        for(int i = 0;i < isConnected.length;i++){
            if(vis[i] == false){
                count++;
                dfs(i, isConnected, vis);
            }
        }
        return count;
    }
}
```

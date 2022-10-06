### 1. Climbing Stairs

```
class Solution {
    public int climb(int index, int target, HashMap<Integer, Integer> hashMap){
        if(index == target){
            return 1;
        }
        else if(index > target){
            return 0;
        }
        
        int currentKey = index;
        int one, two;
        if(hashMap.containsKey(currentKey)){
            return hashMap.get(currentKey);
        }
        one = climb(index+1, target, hashMap);
        two = climb(index+2, target, hashMap);
        hashMap.put(currentKey, one+two);
        return one+two;
    }
    public int climbStairs(int n) {
        int ans = climb(0, n, new HashMap<Integer, Integer>());
        return ans;
    }
}
```

### 2. Minimum Cost Climbing Stairs

```
class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int[] dp = new int[cost.length+1];
        Arrays.fill(dp, -1);
        int zeroth =  minCost(0, cost, dp);
        int first = minCost(1, cost, dp);
        
        return Math.min(zeroth, first);
    }
    
    public int minCost(int index, int[] cost, int[] dp){
        if(index >= cost.length){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        
        int cost1 = 0, cost2 = 0;
        cost1 = minCost(index+1, cost, dp);
        cost2 = minCost(index+2, cost, dp);
        
        dp[index] = Math.min(cost1, cost2) + cost[index];
        return dp[index];
    }
}
```

### 3. Frog Jump

```
import java.util.* ;
import java.io.*; 
public class Solution {
    public static int jump(int n, int[] height, int[] dp){
        if(n == 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int left = 0, right = Integer.MAX_VALUE;
        left = jump(n-1, height, dp) + Math.abs(height[n] - height[n-1]);
        if(n > 1)
            right = jump(n-2, height, dp) + Math.abs(height[n] - height[n-2]);
        
        return dp[n] = Math.min(left, right); 
    }
    public static int frogJump(int n, int heights[]) {

        // Write your code here..
        int[] dp = new int[heights.length];
        Arrays.fill(dp, -1);
        jump(n-1, heights, dp); 
        return dp[n-1];
    }

}
```

### 4. K Jumps

```
public class FrogJumpK{
    public int jumpKtimes(int ind, int[] height, int k){
        if(ind == 0){
            return 0;
        }
        int minStep = Integer.MAX_VALUE;
        int step = 0;
        for(int i = 1;i <= k;i++){
            if(ind-i >= 0){
                step = jumpKtimes(ind-i, height, k) + Math.abs(height[ind] - height[ind-i]);
                minStep = Math.min(minStep, step);
            }
            else{
                break;
            }
        }
        return minStep;
    }

    public int frogJump(int[] height, int k){
        return jumpKtimes(height.length-1, height, k);
    }
}
```

### 5. Maximum Sum of Non-Adjacent Elements

```
import java.util.* ;

public class Solution {
    public static int maxadjacent(int i, ArrayList<Integer> nums, int[] dp){
        if(i >= nums.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        
        int take = nums.get(i) + maxadjacent(i+2, nums, dp);
        int notTake = 0 + maxadjacent(i+1, nums, dp);
        
        return dp[i] = Math.max(take, notTake);
    }
	public static int maximumNonAdjacentSum(ArrayList<Integer> nums) {
		// Write your code here.
        int[] dp = new int[nums.size()];
        Arrays.fill(dp, -1);
        return maxadjacent(0, nums, dp);
	}
}
```
### 1. Binary Tree Paths

```
class Solution {
    public void treePaths(TreeNode root, String s, List<String> list){
        if(root == null){
            return;
        }
        if(root.right == null && root.left == null){
            list.add(s+root.val);
            return;
        }
        treePaths(root.right, s+root.val+"->", list);
        treePaths(root.left, s+root.val+"->", list);
    }
    public List<String> binaryTreePaths(TreeNode root) {
        if(root == null){
            return new ArrayList<String>();
        }
        List<String> list = new ArrayList<String>();
        if(root.right == null && root.left == null){
            list.add(root.val+"");
            return list;
        }

        treePaths(root.left, root.val+"->",list);
        treePaths(root.right, root.val+"->", list);
        return list;
    }
}
```

### 2. Path Sum

```
class Solution {
   
    public boolean hasPathSum(TreeNode root, int targetSum) {
        if(root == null){
            return false;
        }
        if(targetSum - root.val == 0 && root.left == null && root.right == null){
            return true;
        }
        return hasPathSum(root.left, targetSum - root.val) || hasPathSum(root.right, targetSum - root.val);
    }
}
```

### 3. Path Sum II

```
class Solution {
    public void path(TreeNode root, int targetSum, int currentSum, List<Integer> curr, List<List<Integer>> list){
        if(root == null){
            return;
        }
        curr.add(root.val);
        currentSum += root.val;
        if(root.right == null && root.left == null){
            if(targetSum == currentSum){
                list.add(new ArrayList<Integer>(curr));
            }
            curr.remove(curr.size()-1);
            return;
        }
        path(root.left, targetSum, currentSum, curr, list);
        path(root.right, targetSum , currentSum, curr, list);
        curr.remove(curr.size()-1);
    }
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        List<Integer> curr = new ArrayList<Integer>();
        if(root == null){
            return list;
        }
        path(root, targetSum, 0, curr,list);
        return list;
    }
}
```

### 4. Smallest String starting from Leaf

```
class Solution {
    public String smallestLeaf(TreeNode root, String s){
        if(root == null){
            return "";
        }
        if(root.left == null && root.right == null){
            return ((char)(root.val + 97) + s);
        }
        String s1 = smallestLeaf(root.left, (char)(root.val + 97)+s);
        String s2 = smallestLeaf(root.right, (char)(root.val + 97)+s);
        
        if(s1.equals("")){
            return s2;
        }
        if(s2.equals("")){
            return s1;
        }
        if(s1.compareTo(s2) <= 0){
            s = s1;
        }
        else{
            s = s2;
        }
        return s;
    }
    public String smallestFromLeaf(TreeNode root) {
        return smallestLeaf(root, "");
    }
}
```

### 5. Sum Root to Leaf Numbers

```
class Solution {
    public int sum(TreeNode root, int sum){
        if(root == null){
            return 0;
        }
        if(root.right == null && root.left == null){
            return sum*10 + root.val;
        }
        int l = sum(root.left, sum*10 + root.val);
        int r = sum(root.right, sum*10 + root.val);
        
        return l+r;
    }
    public int sumNumbers(TreeNode root) {
        return sum(root, 0);
    }
}
```

### 6. Height Balanced Tree

```
class Solution {
    boolean flag = true;
    public int height(Tree root){
        if(root == null){
            return 0;
        }
        int l = height(root.left);
        int r = height(root.right);
        
        if(Math.abs(l-r) > 1){
            flag = false;
        }
        return Math.max(l,r) + 1;
    }
    public boolean solve(Tree root) {
        if(root == null){
            return true;
        }
        if(root.left == null && root.right == null){
            return true;
        }
        height(root);
        return flag;
    }
}
```

### 7. Counting Maximal Value Roots in Binary Tree

```
class Solution {
    int count = 0;
    public int sum(Tree root, int max){
        if(root == null){
            return 0;
        }
        if(root.left == null && root.right == null){
            count++;
            return root.val;
        }

        int l = sum(root.left, max);
        int r = sum(root.right, max);

        if(l <= root.val && r <= root.val){
            count++;
        }

        max = Math.max(Math.max(l,r), root.val);
        return max;
    }
    public int solve(Tree root) {
        if(root == null){
            return 0;
        }
        sum(root, Integer.MIN_VALUE);
        return count;
    }
}
```

### 8. LinkedList to ZigZag Tree Path

```
class Solution {
    Tree root, temp;
    public Tree solve(LLNode node) {
        if(node == null){
            return null;
        }
        root = new Tree(node.val);
        temp = root;
        while(node != null && node.next != null){
            if(node.next.val < node.val){
                temp.left = new Tree(node.next.val);
                temp = temp.left;
            }
            else{
                temp.right = new Tree(node.next.val);
                temp = temp.right;
            }
            node  = node.next;
            
        }
        return root;
    }
}
```

### 9. Inverted Subtree

```
class Solution {
    public boolean solve(Tree source, Tree target) {
        if (target == null)
            return source == target;
        return check(source, target) || solve(source, target.left) || solve(source, target.right);
    }

    public boolean check(Tree s, Tree t) {
        if (s == null || t == null)
            return s == t;
        if (s.val != t.val)
            return false;
        return check(s.left, t.right) && check(s.right, t.left)
            || check(s.left, t.left) && check(s.right, t.right);
    }

}
```
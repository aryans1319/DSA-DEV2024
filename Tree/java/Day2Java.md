### 1. Same Tree

```
class Solution {
    public boolean sameT(TreeNode p, TreeNode q){
        if(p == null || q == null){
            return (p==q);
        }
        return (p.val == q.val) && sameT(p.left, q.left) && sameT(p.right, q.right);
    }
    public boolean isSameTree(TreeNode p, TreeNode q) {
        return sameT(p,q);
    }
}
```

### 2. Symmetric Tree

```
class Solution {
    public boolean isSymmetric(TreeNode root) {
        Queue<TreeNode> q1 = new LinkedList<TreeNode>();
        Queue<TreeNode> q2 = new LinkedList<TreeNode>();
        q1.add(root.left);
        q2.add(root.right);
        while(!q1.isEmpty() && !q2.isEmpty()){
            TreeNode leftNode = q1.poll();
            TreeNode rightNode = q2.poll();
            if(leftNode == null && rightNode == null){
                continue;
            }
            if(leftNode == null && rightNode != null){
                return false;
            }
            if(leftNode != null && rightNode == null){
                return false;
            }
            if(leftNode.val != rightNode.val){
                return false;
            }
            q1.add(leftNode.left);
            q1.add(leftNode.right);
            q2.add(rightNode.right);
            q2.add(rightNode.left);
        }
        return (q1.size() == q2.size());
    }
}
```

### 3. Maximum Depth of BT

```
class Solution {
    public int height(TreeNode root){
        if(root == null){
            return 0;
        }
        return Math.max(height(root.left),height(root.right)) + 1;
    }
    public int maxDepth(TreeNode root) {
        return height(root);
    }
}
```

### 4. Balanced BT

```
class Solution {
    public int balance(TreeNode root){
        if(root == null){
            return 0;
        }
        int leftSide = balance(root.left);
        if(leftSide == -1){
            return -1;
        }
        int rightSide = balance(root.right);
        if(rightSide == -1){
            return -1;
        }
        
        if(Math.abs(leftSide - rightSide) > 1){
            return -1;
        } 
        return (Math.max(leftSide, rightSide) + 1);
    }
    public boolean isBalanced(TreeNode root) {
        if(root == null){
            return true;
        }
        int diff = balance(root);
        return (diff != -1);
    }
}
```

### 5. Minimum Depth of BT

```
class Solution {
    public int height(TreeNode root){
        if(root == null){
            return 0;
        }
        
        if(root.left == null){
            return height(root.right) + 1;
        }
        if(root.right == null){
            return height(root.left) + 1;
        }
        return Math.min(height(root.left), height(root.right)) + 1;
    }
    public int minDepth(TreeNode root) {
        return height(root);
    }
}
```

### 6. Merge two BT

```
class Solution {
    public TreeNode merge(TreeNode root1, TreeNode root2){
        if(root1 == null && root2 == null){
            return null;
        }
        if(root1 == null){
            return root2;
        }
        if(root2 == null){
            return root1;
        }
        TreeNode root = new TreeNode(root1.val + root2.val);
        root.left = merge(root1.left, root2.left);
        root.right = merge(root1.right, root2.right);
        return root;
    }
    public TreeNode mergeTrees(TreeNode root1, TreeNode root2) {
        return merge(root1, root2);
    }
}
```

### 7. Diameter of BT

```
class Solution {
    public int height(TreeNode root, int[] ans){
        if(root == null){
            return 0;
        }
        int leftSide = height(root.left, ans);
        int rightSide = height(root.right, ans);
        ans[0] = Math.max(ans[0], leftSide+rightSide);
        return Math.max(leftSide, rightSide)+1;
    }
    public int diameterOfBinaryTree(TreeNode root) {
        int[] ans = new int[1];
        height(root, ans);
        return ans[0];
    }
}
```

### 8. Invert BT

```
class Solution {
    public TreeNode invert(TreeNode root){
        if(root == null){
            return null;
        }
        TreeNode temp = root.right;
        root.right = root.left;
        root.left = temp;
        TreeNode leftSide = invert(root.left);
        TreeNode rightSide = invert(root.right);
        
        root.right = rightSide;
        root.left = leftSide;
        return root;
    }
    public TreeNode invertTree(TreeNode root) {
        return invert(root);
    }
}
```

### 9. BT Tilt

```
class Solution {
    public int sumTilt(TreeNode root, int[] ans){
        if(root == null){
            return 0;
        }
        int l = 0, r = 0; 
        l = sumTilt(root.left, ans);
        r = sumTilt(root.right,ans);
        
        int subtree = l + r + root.val;
        root.val = Math.abs(l-r);
        ans[0] += root.val;
        
        return subtree;
    }
    public int findTilt(TreeNode root) {
        int[] ans = new int[1];
        sumTilt(root, ans);
        return ans[0];
    }
}
```

### Thank You!
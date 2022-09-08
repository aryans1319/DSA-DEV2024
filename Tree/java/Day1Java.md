### 1. Inorder Traversal

- Iterative
```
class Solution {
    
    Stack<TreeNode> stack = new Stack<>();
    
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> inorder = new ArrayList<>();
        
        stack.push(root);
        
        while(!stack.empty()) {
            TreeNode pop = stack.pop();
            
            if (pop == null) continue;
            if (pop.left == null && pop.right == null) {
                inorder.add(pop.val);
                continue;
            }
            
            stack.push(pop.right);
            stack.push(pop);
            stack.push(pop.left);
            
            pop.right = null;
            pop.left = null;

        }
        
        return inorder;
    }
}
```

- Recursive
```
class Solution {
    public void inorder(TreeNode root, List<Integer> list){
        if(root == null){
            return;
        }
        inorder(root.left, list);
        list.add(root.val);
        inorder(root.right, list);
    }
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList<Integer>();
        inorder(root, list);
        return list;
    }
}
```

### 2. PreOrder Traversal

- Iterative
```
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        if(root == null){
            return new ArrayList<Integer>();
        }
        List<Integer> list = new ArrayList<Integer>();
        Stack<TreeNode> st = new Stack<TreeNode>();
        st.push(root);
        while(!st.isEmpty()){
            TreeNode temp = st.pop();
            list.add(temp.val);
            if(temp.right != null){
                st.push(temp.right);
            }
            if(temp.left != null){
                st.push(temp.left);
            }
        }
        return list;
    }
}
```

-Recursive
```
class Solution {
    public static void preorder(TreeNode root, List<Integer> list){
        list.add(root.val);
        if(root.left != null) preorder(root.left, list);
        if(root.right != null) preorder(root.right, list);
    }
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> list = new LinkedList<>();
        if(root == null) return list;
        preorder(root, list);
        return list;
    }
}
```

### 3. PostOrder Traversal

- Iterative
```
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        Stack<TreeNode> s1 = new Stack<TreeNode>();
        Stack<TreeNode> s2 = new Stack<TreeNode>();
        List<Integer> list = new ArrayList<Integer>();
        
        if(root == null){
            return list;
        }
        
        s1.push(root);
        while(s1.isEmpty() == false){
            root = s1.pop();
            s2.push(root);
            if(root.left != null){
                s1.push(root.left);
            }
            if(root.right != null){
                s1.push(root.right);
            }
        }
        while(s2.isEmpty() == false){
            list.add(s2.pop().val);
        }
        return list;
    }
}
```

- Recursive
```
class Solution {
    public static void postorder(TreeNode root, List<Integer> list){
        
        if(root.left != null) postorder(root.left, list);
        if(root.right != null) postorder(root.right, list);
        list.add(root.val);
    }
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> list = new LinkedList<>();
        if(root == null) return list;
        postorder(root, list);
        return list;
    }
}
```

### 4. ZigZag Order Traversal

```
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if(root == null){
            return new ArrayList<List<Integer>>();
        }
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.add(root);
        int i = 0;
        while(!q.isEmpty())
        {
            List<Integer> curr = new ArrayList<Integer>();
            int size = q.size();
            for(int j = 0; j < size;j++){
                TreeNode temp = q.poll();
                if(temp.left != null){
                    q.add(temp.left);
                }
                if(temp.right != null){
                    q.add(temp.right);
                }
                curr.add(temp.val);
            }
            if(i%2 != 0){
                Collections.reverse(curr);
            }
            list.add(curr);
            i++;
        }
        return list;
    }
}
```

### 5. Level Order Traversal

```
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {   
        ArrayList<List<Integer>> list = new ArrayList<List<Integer>>();
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        if(root == null){
            return list;
        }
        q.add(root);
        while(!q.isEmpty()){
            ArrayList<Integer> ds = new ArrayList<Integer>();
            int size = q.size();
            for(int i = 0;i < size;i++){
                TreeNode curr = q.poll();
                if(curr != null){
                    ds.add(curr.val);
                }
                if(curr.left != null){
                    q.add(curr.left);
                }
                if(curr.right != null){
                    q.add(curr.right);
                }
            }
            list.add(ds);
        }
        return list;
    }
}
```

### 6. Level Order Traversal II

```
class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        ArrayList<List<Integer>> list = new ArrayList<List<Integer>>();
        if(root == null){
            return list;
        }
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.add(root);
        while(!q.isEmpty()){
            ArrayList<Integer> curr = new ArrayList<Integer>();
            int size = q.size();
            for(int i = 0;i < size;i++){
                TreeNode temp = q.poll();
                if(temp != null){
                    curr.add(temp.val);
                }
                if(temp.left != null){
                    q.add(temp.left);
                }
                if(temp.right != null){
                    q.add(temp.right);
                }
            }
            list.add(0,curr);
        }
        return list;
    }
}
```

### Thank you!
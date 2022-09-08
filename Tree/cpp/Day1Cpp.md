### 1.  PostOrder Traversal


// Iterative Solution
```
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*> st;
        if(root == NULL) return ans;
        st.push(root);
        while(!st.empty()){
            TreeNode *currentNode = root;
            currentNode = st.top();
            st.pop();
            ans.push_back(currentNode->val);
            if(currentNode->left != NULL){
                st.push(currentNode->left);
            }
            if(currentNode->right != NULL){
                st.push(currentNode->right);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// Recursive Solution

class Solution {
public:
    void postOrder(TreeNode *root, vector<int>&ans){
        if(root == NULL) return;
        postOrder(root->left,ans);
        postOrder(root->right,ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        postOrder(root, ans);
        return ans;
    }
};
```

### 2. PreOrder Traversal
```
// Iterative
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*> st;
        
        if(root == NULL) return ans;
        st.push(root);
        
        while(!st.empty()){
            TreeNode *currentNode = root;
            currentNode = st.top();
            st.pop();
            ans.push_back(currentNode->val);
            if(currentNode->right != NULL){
                st.push(currentNode->right);
            }
            if(currentNode->left != NULL){
                st.push(currentNode->left);
            }
        }
        return ans;
    }
};

// Recursive

class Solution {
public:
    void preOrder(TreeNode *root, vector<int>&ans){
        if(root == NULL) return;
        ans.push_back(root->val);
        preOrder(root->left,ans);
        preOrder(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        preOrder(root, ans);
        return ans;
    }
};
```

### 3. Inorder Traversal
```
// Recursive

class Solution {
public:
    void inorder(TreeNode *root, vector<int>&ans){
        if(root == NULL) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        return ans;
    }
};
```

### 4. Level Order Traversal

```
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == NULL) return ans;
        
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>level;
            for(int i=0; i<size; i++){
                TreeNode *node = q.front();
                q.pop();
                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
```

### 5. Level Order Traversal 2

```
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == NULL) return ans;
        
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>level;
            for(int i=0; i<size; i++){
                TreeNode *node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
            }
            ans.insert(ans.begin(), level);
        }
        
        return ans;
    }
};
```

### 6. Zig-Zag Traversal

```
class Solution {
public:
    /*
    The approach here is to track the traversal from left to right and right to left
    is to keep a bool value, set it true(0) L->R and false(1) R->L
    if true insert at current index i else insert from the end
    Rest everything remains the same!
    */
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        bool leftToRight = true;
        
        while(!q.empty()){
            int size = q.size();
            vector<int>rows(size);
            
            for(int i = 0; i<size; i++){
                TreeNode *node = q.front();
                q.pop();
                
                int index = (leftToRight) ? i : (size-i-1);
                rows[index] = node->val;
                
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            leftToRight = !leftToRight;
            ans.push_back(rows);
        }
        return ans;
    }
};
```

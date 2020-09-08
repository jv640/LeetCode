/*
  Problem Name  : Sum of Root To Leaf Binary Numbers
  Description   : Given a binary tree, each node has value 0 or 1. Each root-to-leaf path represents a binary number starting with the most significant bit. 
                  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
                  For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.
                  Return the sum of these numbers.
  Example 1:
      Input:      [1,0,1,0,1,0,1]
      Output:     22
      Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
  Note:
                  The number of nodes in the tree is between 1 and 1000.
                  node.val is 0 or 1.
                  The answer will not exceed 2^31 - 1.
*/
// approch is to make string for every path then at end calculate value and add it in sum O(N) O(n)
// code
      void dfs(TreeNode* root, int* sum, string s){
        // cout<<*sum<<" ";
        s += to_string(root->val);
        if(!root->left && !root->right){
            int n = s.length()-1;
            int num = 0;
            // cout<<s<<" ";
            for(int i = 0; i<s.length(); i++)
                num += (s[i]-'0')*pow(2, n--);
            // cout<<num<<" ";
            *sum = *sum + num;
        }
        if(root->left)
            dfs(root->left, sum, s);
        if(root->right)
            dfs(root->right, sum, s);
        
    }
    int sumRootToLeaf(TreeNode* root) {
        if(!root) return 0;
        int sum = 0;
        dfs(root, &sum, "");
        return sum;
    }
    
// Without string using shift operator
int rootToLeaf = 0;
    
    void preorder(TreeNode* r, int currNumber) {
        if (r != nullptr) {
            currNumber = (currNumber << 1) | r->val;
            // if it's a leaf, update root-to-leaf sum
            if (r->left == nullptr && r->right == nullptr) {
                rootToLeaf += currNumber;
            }
            preorder(r->left, currNumber);
            preorder(r->right, currNumber);
        }
    }
    
    int sumRootToLeaf(TreeNode* root) {
        preorder(root, 0);
        return rootToLeaf;
    }

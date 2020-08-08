/*
  Problem name: Path Sum III
  Description : You are given a binary tree in which each node contains an integer value.Find the number of paths that sum to a given value.
                The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
                The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.
  Example:      root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
                    10
                   /  \
                  5   -3
                 / \    \
                3   2   11
               / \   \
              3  -2   1
              Return 3. The paths that sum to 8 are:
              1.  5 -> 3
              2.  5 -> 2 -> 1
              3. -3 -> 11
              
*/
// Code with O(n2) solution.
    int count = 0;
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL) return 0;
        
        findpathsum(root, 0, sum);
        pathSum(root->left, sum);
        pathSum(root->right, sum);
        
        return count;
    }
    void findpathsum(TreeNode* node, int currsum, int target){
        if(node == NULL)return;
        currsum += node->val;
        if(target == currsum)count++;
        findpathsum(node->left, currsum, target);
        findpathsum(node->right, currsum, target);
    }
    
// Approach here is to take two pointer fix one at root initially then traverse whole tree and calculate sum of paths whenever sum matches target count++
//  And iterate like this for every node in tree so O(n2) solution.

// Another O(n) approach is using map. store sum of path in map. check codebix YT fo that

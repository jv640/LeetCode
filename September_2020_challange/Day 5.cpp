/*
  Problem Name  :   All Elements in Two Binary Search Trees
  Description   :   Given two binary search trees root1 and root2. Return a list containing all the integers from both trees sorted in ascending order.
  Example 1:
    Input:          root1 = [2,1,4], root2 = [1,0,3]
    Output:         [0,1,1,2,3,4]
  Example 2:
    Input:          root1 = [0,-10,10], root2 = [5,1,7,0,2]
    Output:         [-10,0,0,1,2,5,7,10]
  Example 3:
    Input:          root1 = [], root2 = [5,1,7,0,2]
    Output:         [0,1,2,5,7]
  Example 4:
    Input:          root1 = [0,-10,10], root2 = []
    Output:         [-10,0,10]
  Example 5:
    Input:          root1 = [1,null,8], root2 = [8,1]
    Output:         [1,1,8,8]
  Constraints:
                    Each tree has at most 5000 nodes.
                    Each node's value is between [-10^5, 10^5].
*/

// So first approach is to make 2 seperate vectors and perform inorder traversal on both tree and save element in vectors then merge them using mergre function O(n) O(n)
// Other is to go to bottom left on both tree store middle elements on stack and at last compare them then save in final vector. Here we dont need intermediate vectors O(n) O(height)
// code for 2nd appraoch
      vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        int val1 = INT_MAX, val2 = INT_MAX;
        TreeNode* curr1 = root1;
        TreeNode* curr2 = root2;
        vector<int> res;
        stack<TreeNode* > s1, s2;
        bool found1 = false, found2 = false;
        while(1){
            while(!found1){
                if(curr1){
                    s1.push(curr1);
                    curr1 = curr1->left;
                }
                else{
                    if(s1.empty())
                        found1 = true;
                    else{
                        curr1 = s1.top();
                        s1.pop();
                        val1 = curr1->val;
                        curr1 = curr1->right;
                        found1 = true;
                    }
                }
            }
            while(!found2){
                if(curr2){
                    s2.push(curr2);
                    curr2 = curr2->left;
                }
                else{
                    if(s2.empty())
                        found2 = true;
                    else{
                        curr2 = s2.top();
                        s2.pop();
                        val2 = curr2->val;
                        curr2 = curr2->right;
                        found2 = true;
                    }
                }
            }
            if(found1 && found2 && s1.empty() && s2.empty() && !curr1 && !curr2 && val1 == INT_MAX && val2 == INT_MAX)
                break;
            else if(found1 && s1.empty() && !curr1 && val1 == INT_MAX){
                res.push_back(val2);
                val2 = INT_MAX;
                found2 = false;
            }
            else if(found2 && s2.empty() && !curr2 && val2 == INT_MAX){
                res.push_back(val1);
                val1 = INT_MAX;
                found1 = false;
            }
            else{
                if(val1<=val2){
                    res.push_back(val1);
                    val1 = INT_MAX;
                    found1 = false;
                }
                else{
                    res.push_back(val2);
                    val2 = INT_MAX;
                    found2 = false;
                }
            }
        }
        return res;
    }

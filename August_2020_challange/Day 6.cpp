/*
  Problem name:   Find All Duplicates in an Array
  Description :   Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
                  Find all the elements that appear twice in this array.
  Note        :   Could you do it without extra space and in O(n) runtime?
  Example:
        Input:[4,3,2,7,8,2,3,1]
        Output:[2,3]
        
*/

// Code

    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(nums[abs(nums[i])-1]<0)
                result.push_back(abs(nums[i]));
            else
                nums[abs(nums[i])-1] = nums[abs(nums[i])-1] * -1;
        }
        return result;
        
    }

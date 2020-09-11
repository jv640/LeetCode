/*
  Problem Name  : Maximum Product Subarray
  Description   : Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.
  Example 1:
    Input:        [2,3,-2,4]
    Output:       6
    Explanation:  [2,3] has the largest product 6.
  Example 2:
    Input:        [-2,0,-1]
    Output:       0
    Explanation:  The result cannot be 2, because [-2,-1] is not a subarray.
*/
// code
      int maxProduct(vector<int>& arr) {
        int n = arr.size();
        int minVal = arr[0]; 
        int maxVal = arr[0]; 

        int maxProduct = arr[0]; 

        for (int i = 1; i < n; i++) { 
            if (arr[i] < 0) 
                swap(maxVal, minVal); 
            minVal = min(arr[i], minVal * arr[i]); 
            maxProduct = max(maxProduct, maxVal); 
        } 
        return maxProduct; 
    }

/*
  Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t 
  and the absolute difference between i and j is at most k.
  Example 1:
    Input:  nums = [1,2,3,1], k = 3, t = 0
    Output: true
  Example 2:
    Input:  nums = [1,0,1,1], k = 1, t = 2
    Output: true
  Example 3:
    Input:  nums = [1,5,9,1,5,9], k = 2, t = 3
    Output: false
*/
// Code
      bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(t < 0) return false;
        set<int> s;
        for(int i = 0; i < nums.size(); i++){
            if(i > k)
                s.erase(nums[i - k - 1]);
            int lo = (nums[i] < INT_MIN + t)? INT_MIN:nums[i]-t;
            int hi = (nums[i] > INT_MAX - t)? INT_MAX:nums[i]+t;
            if(s.lower_bound(lo) != s.end() && *(s.lower_bound(lo)) <= hi)
                return true;
            s.insert(nums[i]);
        }
        return false;
    }

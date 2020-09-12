/*
  Problem Name  : Combination Sum III
  Description   : Find all possible combinations of k numbers that add up to a number n, 
                  given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
  Note:
                  All numbers will be positive integers.
                  The solution set must not contain duplicate combinations.
  Example 1:
      Input:      k = 3, n = 7
      Output:     [[1,2,4]]
  Example 2:
      Input:      k = 3, n = 9
      Output:     [[1,2,6], [1,3,5], [2,3,4]] 
*/

// Here as we can see its asking for all combination means dfs
// code
    void dfs(vector<int> arr, int k, int target, int start, set<vector<int>> &s, vector<int> &v){
        if(target == 0 && v.size() == k){
            s.insert(v);
            return;
        }
        else if(target < 0 || v.size() == k)
            return;
        for(int i = start; i<9; i++){
            v.push_back(arr[i]);
            dfs(arr, k, target-arr[i], i+1, s, v);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8 ,9};
        set<vector<int>> s;
        vector<int> v;
        dfs(arr, k, n, 0, s, v);
        vector<vector<int>> res;
        for(auto i = s.begin(); i != s.end(); i++)
            res.push_back(*i);
        return res;
    }

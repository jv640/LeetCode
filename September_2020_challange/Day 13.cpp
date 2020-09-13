/*
  Problem Name  : Insert Interval
  Description   : Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
                  You may assume that the intervals were initially sorted according to their start times.
  Example 1:
    Input:        intervals = [[1,3],[6,9]], newInterval = [2,5]
    Output:       [[1,5],[6,9]]
  Example 2:
    Input:        intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
    Output:       [[1,2],[3,10],[12,16]]
    Explanation:  Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
    NOTE:         input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/
/*
  Approach is to iterate over given intervals and on iterating we can have 3 situations 
  1st newInterval is on total right of current then simply add current in result and move forward
  2nd newInterval is on total left of current interval then add newInterval in result and make current inteval as newInterval
  3rd overlapping situation then just update the start of newInterval with min(currentInterval[0], newInterval[0]) and ending with max(currInterval[1], newInterval[1])
*/
// code
      vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;
        int idx = 0;
        for(int i = 0; i<n; i++){
            if(intervals[i][1] < newInterval[0]){
                res.push_back(intervals[i]);
            }
            else if(intervals[i][0] > newInterval[1]){
                res.push_back(newInterval);
                newInterval = intervals[i];
            }
            else{
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            }
        }
        res.push_back(newInterval);
        return res;
    }

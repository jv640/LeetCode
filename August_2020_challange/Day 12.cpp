/*
  Problem Name  : Pascal's Triangle II
  Description   : Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
                  Note that the row index starts from 0.
                  In Pascal's triangle, each number is the sum of the two numbers directly above it.
  Example:        Input: 3
                  Output: [1,3,3,1]
  Follow up:      Could you optimize your algorithm to use only O(k) extra space?
*/
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        row.push_back(1);
        if(!rowIndex) return row;
        for(int i = 0; i<rowIndex; i++){
            vector<int> back;
            back.push_back(1);
            for(int j = 0; j<row.size()-1; j++){
                back.push_back(row[j] + row[j+1]);
            }
            back.push_back(1);
            row = back;
            back.clear();
        }
        return row;
    }

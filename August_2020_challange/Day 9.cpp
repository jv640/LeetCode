/*
  Problem name :  Rotting Oranges
  Descripiton  :  In a given grid, each cell can have one of three values:
                  the value 0 representing an empty cell;
                  the value 1 representing a fresh orange;
                  the value 2 representing a rotten orange.
                  Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.
                  Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.
  Example 1:      Input: [[2,1,1],[1,1,0],[0,1,1]]
                  Output: 4
  Example 2:      Input: [[2,1,1],[0,1,1],[1,0,1]]
                  Output: -1
                  Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
  Example 3:      Input: [[0,2]]
                  Output: 0
                  Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
  Note:           1 <= grid.length <= 10
                  1 <= grid[0].length <= 10
                  grid[i][j] is only 0, 1, or 2.
*/

// Code

      int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(); // rows
        int n = grid[0].size(); // cols
        int rotten = 0, total = 0, time = 0;
        queue<pair<int, int>> que;
        for(int i = 0; i<m; i++)
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1 || grid[i][j] == 2)total++;
                if(grid[i][j] == 2) que.push(make_pair(i,j));
            }
        if(total == 0)return 0;
        rotten += que.size();
        while(!que.empty()){
            int size = que.size();
            if(total == rotten)return time;
            time++;
            for(int i = 0; i<size; i++){
                pair<int, int> p = que.front();
                que.pop(); 
                // left move
                if(p.second-1 > -1 && grid[p.first][p.second-1] == 1){
                    grid[p.first][p.second-1] = 2;
                    que.push(make_pair(p.first, p.second-1));
                    rotten++;
                }
                // right move
                if(p.second+1 < n && grid[p.first][p.second+1] == 1){
                    grid[p.first][p.second+1] = 2;
                    que.push(make_pair(p.first, p.second+1));
                    rotten++;
                }   // Up move
                if(p.first-1 > -1 && grid[p.first-1][p.second] == 1){
                    grid[p.first-1][p.second] = 2;
                    que.push(make_pair(p.first-1, p.second));
                    rotten++;
                } // Down move
                if(p.first+1 < m && grid[p.first+1][p.second] == 1){
                    grid[p.first+1][p.second] = 2;
                    que.push(make_pair(p.first+1, p.second));
                    rotten++;
                }
                cout<<"h"<<i;
            }
            
        }
        return -1;
    }
    
// Approach is to think like matrix is a graph and we have to applu BFS on it and do following task

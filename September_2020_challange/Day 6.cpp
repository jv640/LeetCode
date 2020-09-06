/*
  Problem Name  : Image Overlap
  Description   : Two images A and B are given, represented as binary, square matrices of the same size.  (A binary matrix has only 0s and 1s as values.)
                  We translate one image however we choose (sliding it left, right, up, or down any number of units), and place it on top of the other image.  
                  After, the overlap of this translation is the number of positions that have a 1 in both images.
                  (Note also that a translation does not include any kind of rotation.)
                  What is the largest possible overlap?
  Example 1:
      Input:      A = [[1,1,0],[0,1,0],[0,1,0]]
                  B = [[0,0,0],[0,1,1],[0,0,1]]
      Output:     3
      Explanation: We slide A to right by 1 unit and down by 1 unit.
  Notes: 
                  1 <= A.length = A[0].length = B.length = B[0].length <= 30
                  0 <= A[i][j], B[i][j] <= 1
*/
// Approach i simply run loop for every possible move in right and down direction and simultaneously in Up left direction and which ever gives maximum i save that O(n4)
// Code
      int calcRD(vector<vector<int>>& a, vector<vector<int>>& b, int x, int y){
        int n = a.size();
        int count = 0;
        for(int i = x, c = 0; c<n && i<n; i++, c++){
            for(int j = y, d = 0; d<n && j<n; j++, d++){
                count += a[c][d] && b[i][j];
            }
        }
        cout<<count;
        return count;
    }
    int calcLU(vector<vector<int>>& a, vector<vector<int>>& b, int x, int y){
        int n = a.size();
        int count = 0;
        for(int i = x, c = 0; c<n && i<n; i++, c++){
            for(int j = y, d = 0; d<n && j<n; j++, d++){
                count += a[i][j] && b[c][d];
            }
        }
        // cout<<count;
        return count;
    }
    int largestOverlap(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size();
        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                count = max(count, max(calcRD(a, b, i, j), calcLU(a, b, i, j)));
            }
        }
        return count;
    }
    
// Better but same complexity solution
class Solution {
    protected int shiftAndCount(int xShift, int yShift, int[][] M, int[][] R) {
        int count = 0;
        int rRow = 0;
        // count the cells of ones in the overlapping zone.
        for (int mRow = yShift; mRow < M.length; ++mRow) {
            int rCol = 0;
            for (int mCol = xShift; mCol < M.length; ++mCol) {
                if (M[mRow][mCol] == 1 && M[mRow][mCol] == R[rRow][rCol])
                    count += 1;
                rCol += 1;
            }
            rRow += 1;
        }
        return count;
    }

    public int largestOverlap(int[][] A, int[][] B) {
        int maxOverlaps = 0;

        for (int yShift = 0; yShift < A.length; ++yShift)
            for (int xShift = 0; xShift < A.length; ++xShift) {
                // move one of the matrice up and left and vice versa.
                // (equivalent to move the other matrix down and right)
                maxOverlaps = Math.max(maxOverlaps, shiftAndCount(xShift, yShift, A, B));
                maxOverlaps = Math.max(maxOverlaps, shiftAndCount(xShift, yShift, B, A));
            }

        return maxOverlaps;
    }
}

// As we see we are doing extra work for cell with 0 again and again to avoid that we can use linear transformation
// Other is using convonution overlapping

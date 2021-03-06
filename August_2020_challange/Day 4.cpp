/*
    Problem : Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
    Example 1:
        Input: 16
        Output: true
    Example 2:
        Input: 5
        Output: false
    Follow Up:
        Follow up: Could you solve it without loops/recursion?
*/

// Code
    bool isPowerOfFour(int num) {
        if(!num) return false;
        return floor(log(num)/log(4)) == ceil(log(num)/log(4));
    }
    
/*
  There are lots of approach for this question
  A-1 : simple take log(num) on base 4 if this is an integer then it is power of 4 otherwise not.
  A-2 : Another solution is to keep dividing the number by 4, i.e, do n = n/4 iteratively.
        In any iteration, if n%4 becomes non-zero and n is not 1 then n is not a power of 4, otherwise n is a power of 4.
  A-3 : A number n is a power of 4 if following conditions are met.
          a) There is only one bit set in the binary representation of n (or n is a power of 2)
          b) The count of zero bits before the (only) set bit is even.
          For example: 16 (10000) is power of 4 because there is only one bit set and count of 0s before the set bit is 4 which is even.
*/

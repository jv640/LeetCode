/*
  Problem Name  : H-Index
  Description   : Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.
                  According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, 
                  and the other N − h papers have no more than h citations each."
  Example       :
                  Input: citations = [3,0,6,1,5]
                  Output: 3 
                  Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had 
                               received 3, 0, 6, 1, 5 citations respectively. 
                               Since the researcher has 3 papers with at least 3 citations each and the remaining 
                               two with no more than 3 citations each, her h-index is 3.
                  Note: If there are several possible values for h, the maximum one is taken as the h-index. 
*/

// Code
      int hIndex(vector<int>& citations) {
        int n = citations.size();
        int bucket[n+1];
        memset(bucket, 0, sizeof(bucket));
        for(int i = 0; i<n; i++){
            if(citations[i] > n)
                bucket[n]++;
            else
                bucket[citations[i]]++;
        }
        int count = 0;
        for(int i = n; i>-1; i--){
            count += bucket[i];
            if(count >= i)
                return i;
        }
        return 0;
    }
    
// Approach is using bucket sort we will make a array for counting frequency of papers so value in bucket array will tell quantity of paper and index of 
// index of bucket will tell the quality of paper so after getting frequency we will see from right that weather given total papers have this citation or not

// another approach is to use sort then appy binary search but it O(nlogn) and above is O(n)

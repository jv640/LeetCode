/*
  Problem Name  :   Longest Palindrome
  Description   :   Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
                    This is case sensitive, for example "Aa" is not considered a palindrome here.
  Note:             Assume the length of given string will not exceed 1,010.
  Example:
        Input   :   "abccccdd"
        Output  :   7
  Explanation:      One longest palindrome that can be built is "dccaccd", whose length is 7.
*/
// Code

      int longestPalindrome(string s) {
        vector<int> small(26,0);
        vector<int> cap(26,0);
        int n = s.length();
        if(n == 1) return 1;
        for(int i = 0; i<n; i++){
            if(isupper(s[i]))
                cap[s[i]-'A']++;
            if(islower(s[i]))
                small[s[i]-'a']++;
        }
        int count = 0;
        for(int i = 0; i<26; i++){
            if(small[i]%2 == 0)
                count += small[i];
            else if(small[i]%2 != 0 && small[i]>2)
                count += small[i]-1;
            if(cap[i]%2 == 0)
                count += cap[i];
            else if(cap[i]%2 != 0 && cap[i]>2)
                count += cap[i]-1;
        }
        
        for(int i = 0; i<26; i++){
            if(small[i]%2 != 0){
                count++;
                break;
            }
            if(cap[i]%2 != 0){
                count++;
                break;
            }
        }
        
    return count;
    }

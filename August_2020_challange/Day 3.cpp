/*
  Description:
      Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
      Note: For the purpose of this problem, we define empty string as valid palindrome.

  Example 1:
      Input: "A man, a plan, a canal: Panama"
      Output: true
  Example 2:
      Input: "race a car"
      Output: false
      
  Constraints:
      s consists only of printable ASCII characters.
*/

// Code

      bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int n = s.length()-1;
        int i = 0;
        while(i<n){
            if(!isalnum(s[i]))
                i++;
            else if(!isalnum(s[n]))
                n--;
            else if(s[i] == s[n]){
                i++;
                n--;
            }
            else
                return false;
        }
        return true;
        
      }

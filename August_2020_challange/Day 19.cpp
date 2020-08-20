/*
  Problem Name :  Goat Latin
  Description  :  A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.
                  We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)
                  The rules of Goat Latin are as follows:
                  If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
                  For example, the word 'apple' becomes 'applema'.
                  If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
                  For example, the word "goat" becomes "oatgma".
                  Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
                  For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
                  Return the final sentence representing the conversion from S to Goat Latin. 
  Example 1:
      Input:      "I speak Goat Latin"
      Output:     "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
  Example 2:
      Input:      "The quick brown fox jumped over the lazy dog"
      Output:     "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
  Notes:
                  S contains only uppercase, lowercase and spaces. Exactly one space between each word.
                  1 <= S.length <= 150. 
*/

// Code
      string toGoatLatin(string S) {
        string res;
        vector<string> words;
        set <char> vowels;
        vowels.insert('a');
        vowels.insert('e');
        vowels.insert('i');
        vowels.insert('o');
        vowels.insert('u');
        vowels.insert('A');
        vowels.insert('E');
        vowels.insert('I');
        vowels.insert('O');
        vowels.insert('U');
        string str;
        for(int i = 0; i<S.length(); i++){
            if(S[i] == ' '){
                words.push_back(str);
                str.clear();
            }
            else
                str += S[i];
        }
        words.push_back(str);
        // for(int i = 0; i<words.size(); i++)
        //     cout<<words[i];
        string add = "maa";
        for(int i = 0; i<words.size(); i++){
            if(vowels.find(words[i][0]) != vowels.end()){
                string temp = words[i] + add;
                res += temp;
                // cout<<temp;
            }
            else{
                string temp = words[i].substr(1) +words[i][0] + add;
                // cout<<temp;
                res += temp;
            }
            res += ' ';
            // cout<<" ";
            add += 'a';
        }
        return res.substr(0, res.length()-1);
    }

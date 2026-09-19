class Solution {
public:
    bool isPalindrome(string s) {
        std::unordered_set<char> char_set;

    for (char ch = 'a'; ch <= 'z'; ++ch) {
        char_set.insert(ch);
    }

    for (char ch = 'A'; ch <= 'Z'; ++ch) {
        char_set.insert(ch);
    }

    for (char ch = '0'; ch <= '9'; ++ch) {
        char_set.insert(ch);
    }
        int i = 0, j = s.size() - 1; 
        while(j > i){
            while (i< s.size() && !char_set.count(s[i])  ){
                i++;
            }
            while (j >= 0  && !char_set.count(s[j])){
                j--;
            }
           // return s[i];
           char a = toupper(s[i]);
           char b = toupper(s[j]);
            if ( a != b ) return false;
            i ++; j--;
        }
        return true;
    }
};

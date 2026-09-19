class Solution {
public:
    bool isAnagram(string s, string t) {
     int count[26] = {0};
        for (char c : s){
            count[c - 'a']++;
        }
        for (char c : t){
            count[c - 'a']--;
            if (count[c- 'a']< 0)return false;
        }
        int countr[26] = {0};
        for (char c : t){
            countr[c - 'a']++;
        }
        for (char c : s){
            countr[c - 'a']--;
            if (countr[c- 'a']< 0)return false;
        }
        return true;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool check[10000] = {0};
        int i = 0, j = -1;
        int maxs = 0;
        while (i < s.size()){
            if (check[s[i] ] == true){
                while(check[s[i] ] == true){
                    j++;
                    check[s[j]] = false;
                    }
                }
            maxs = max(maxs, i - j);
            check[s[i] ] = true;
            i++;
        }
        return maxs;
    }
};

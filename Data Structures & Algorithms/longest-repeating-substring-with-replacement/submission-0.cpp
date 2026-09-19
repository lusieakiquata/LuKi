class Solution {
public:
    int characterReplacement(string s, int k) {
        int count [225] ={0};
        int maxcount = 0;
        int res = 0;
        int l = 0;
        for(int r = 0; r< s.size() ;r++){
            count[s[r]] ++;
            maxcount = max(maxcount, count[s[r]]);
            while( (r - l +1) - maxcount > k ){
                count[s[l]]--;
                l++;
            }
            res = max(res, r -l+1);
        }
        return res;
    }
};

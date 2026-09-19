class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> counts1(26, 0), counts2(26, 0);
       if (s1.size() > s2.size()) return false;
        for (int i = 0; i < s1.size() ;i++){
            counts1[s1[i] - 'a']++;
            counts2[s2[i] - 'a']++;
        }
        int matche = 0;
        for (int i = 0; i < 26; i++){
            if (counts1[i] == counts2[i]) matche++;
        }
        if (matche == 26) return true;
        for (int i = s1.size() ; i< s2.size(); i++){
            
            int r = i;
            int l = i - s1.size();

            int idx_r = s2[r] - 'a';
            counts2[idx_r]++;
            if (counts2[idx_r] == counts1[idx_r]) matche++;
            if (counts2[idx_r] == counts1[idx_r] + 1 ) matche--;

            int idx_l = s2[l] - 'a';
            counts2[idx_l]--;
            if (counts2[idx_l] == counts1[idx_l]) matche++;
            if (counts2[idx_l] == counts1[idx_l] - 1 ) matche--;
        if (matche == 26) return true;
            
        }
        return false;
    }
};

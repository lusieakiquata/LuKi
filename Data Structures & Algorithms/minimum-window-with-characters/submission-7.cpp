class Solution {
   public:
    string minWindow(string s, string t) {
        int j = 0;
        if (s.size() < t.size()) return "";
        vector<int> s_count(256, 0), t_count(256, 0);
        for (int i = 0; i < t.size(); i++) {
            t_count[t[i]]++;
        }
        string res;
        int l = 0, r = s.size()+1;
        int s_machet = 0, t_machet = 0;
        for (int i = 0; i < 256; i++) {
            if (t_count[i] > 0) t_machet++;
        }
        for (int i = 0; i < s.size(); i++) {
            s_count[s[i]]++;
            if (s_count[s[i]] == t_count[s[i]] && t_count[s[i]] > 0) {
                s_machet++;
            }
            while (j <= i && t_machet == s_machet ) {
                s_count[s[j]]--;
                if (r > i - j +1){ r = i -j +1; l = j;}
                if (s_count[s[j]] == t_count[s[j]] - 1 && t_count[s[j]] > 0) s_machet--;
                j++;
            }
        }
        return (s.size()+1 == r ) ? "": s.substr(l, r);
    }
};

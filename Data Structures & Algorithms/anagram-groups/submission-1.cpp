class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > seen;
        for(const string &x : strs){
            int count[26] = {0};
            for (char c : x){
                count[c - 'a']++;
            }
            string key = "";
            for (int i = 0; i< 26; i++){
                key += count[i];
            }
            seen[key].push_back(x);
        }
        vector<vector<string>> v;
        for (auto& pair : seen){
            v.push_back(pair.second);
        }
        return v;
    }
};

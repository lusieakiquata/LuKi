class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > seen;
        for(const string &x : strs){
            string xs = x;
            sort(xs.begin(),xs.end());
            seen[xs].push_back(x);
        }
        vector<vector<string>> v;
        for (auto& pair : seen){
            v.push_back(pair.second);
        }
        return v;
    }
};

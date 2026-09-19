class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> map;
        for (int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
        }
        vector<pair<int, int>> result;
        vector<int> rf;
        for ( auto x : map){
            result.push_back({x.first, x.second});
            
        }
        sort(result.begin(), result.end(), [](auto &a, auto &b) { return a.second > b.second;});
        for (int i = 0; i< k ;i++){rf.push_back(result[i].first);}
        return rf;
    }
};

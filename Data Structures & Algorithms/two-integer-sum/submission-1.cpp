class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> countt;
        for(int i = 0; i< nums.size(); i++){
           countt[nums[i]] =  i;
        }
        for (int i = 0; i< nums.size(); i++){
            if (countt.count(target - nums[i])&& countt[target - nums[i]] != i)
            return vector<int> {i,countt[target - nums[i]]};
        }
        return vector<int>{};
    }
};

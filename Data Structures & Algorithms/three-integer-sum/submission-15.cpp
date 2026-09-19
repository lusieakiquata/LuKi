class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        for (int i = 0; i < nums.size(); i++){
            if (i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k){
                int tong = nums[i]+ nums[j]+ nums[k];
                if (tong > 0 ){
                    k--;
                }
                else if (tong == 0){
                    if (res.size() == 0 || !(res[res.size()-1][0] == nums[i] && res[res.size() - 1][1] == nums[j] && res[res.size() - 1][2] == nums[k]) ){
                    res.push_back({nums[i], nums[j], nums[k]});
                    }
                    k--; j++;
                }
                else {
                    j++;

                }
            }
        }
        return res;
    }
};

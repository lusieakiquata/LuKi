class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> rs(nums.size(), 1);
        int TichT = 1, TichS = 1;
        for(int i = 0; i < nums.size(); i++){
            int j = nums.size() - i -1;
            rs[i] *= TichT;
            TichT *= nums[i];

            rs[j] *= TichS;
            TichS *= nums[j];
        }
        return rs;
    }
};

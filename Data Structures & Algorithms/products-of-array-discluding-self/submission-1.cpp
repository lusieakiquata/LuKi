class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> rs(nums.size(), 1);
        int TichT = 1, TichS = 1, dem = 0;
        for(int i = 0; i < nums.size(); i++){
            rs[i] = TichT;
            TichT *= nums[i];
        }
        for(int i = nums.size() - 1; i >= 0; i--){
            rs[i] *= TichS;
            TichS *= nums[i];
        }
        return rs;
    }
};

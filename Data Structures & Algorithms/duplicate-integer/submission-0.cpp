class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
       map<int,int> M;
       for (int i = 0; i< nums.size(); i++){
            M[nums[i]] ++;
            if (M[nums[i]] == 2) return true;
       }
       return false;
    }
};
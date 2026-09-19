class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> rs(nums.size(), 0);
        int Tich = 1, Tichno0 = 1, dem = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) 
            {
                dem++;
                
            }
            else Tichno0 *= nums[i];
            if (dem == 2) return rs;
            Tich *= nums[i];
        }
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] != 0)
                rs[i] = Tich / nums[i];
            else    
                rs[i] = Tichno0;
        }
        return rs;
    }
};

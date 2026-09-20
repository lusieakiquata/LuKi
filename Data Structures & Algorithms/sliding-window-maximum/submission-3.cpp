#pragma GCC optimize("O3")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("unroll-loops")
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int win = 0;
        vector<int> res;
        deque<int> q; 
        for (int i = 0; i< nums.size(); i++){
            if (!q.empty() && q.front() == i - k)
                q.pop_front();
            while(!q.empty() && nums[q.back()] < nums[i])
                q.pop_back();
            q.push_back(i);
            if (i >= k-1 ) res.push_back(nums[q.front()]);
        }
        return res;
    }
};

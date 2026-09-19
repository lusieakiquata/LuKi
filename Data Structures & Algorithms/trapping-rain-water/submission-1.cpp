class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int maxl = 0, res = 0; 
        int maxr = 0;
        while (i < j ){
            maxl = max(maxl, height[i]);
            maxr = max(maxr, height[j]);
            
            
            if (maxl < maxr){
                res += min(maxl, maxr) - height[i];
                i++;
            }
            else {
                res += min(maxl, maxr) - height[j];
                j--;}
        }
        return res;
    }
};

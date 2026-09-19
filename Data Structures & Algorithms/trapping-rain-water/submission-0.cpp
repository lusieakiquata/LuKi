class Solution {
public:
    int trap(vector<int>& height) {
       int maxleft[200000] ={0};
       int maxright[200000] ={0};
        maxleft[0] = height[0];
       for(int i = 1 ; i< height.size(); i++){
        maxleft[i] = max(height[i], maxleft[i-1]);
       }
       maxright[height.size() -1] = height[height.size() -1];
       for(int i = height.size() - 2 ; i>= 0; i--){
        maxright[i] = max(height[i], maxright[i+1]);
        }
        int res = 0;
        for (int i = 0 ; i< height.size() - 1; i++){
            res += min(maxright[i], maxleft[i]) - height[i];
        }
        return res;
    }
};

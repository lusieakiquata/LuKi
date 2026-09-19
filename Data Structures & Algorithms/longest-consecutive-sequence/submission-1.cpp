class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> Asr;
        int result = 0;
        Asr.insert(nums.begin(), nums.end());
        for( const auto& x : Asr){
            if (!Asr.contains(x- 1)){
                int lenMax = 0;
                while (Asr.contains(x + lenMax)){
                    lenMax ++;
                }
                result = max(result, lenMax);
            }
        }
        return result;
    }
};

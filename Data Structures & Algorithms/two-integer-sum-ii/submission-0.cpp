class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
       while(j > i) {
        int Tong = numbers[i] + numbers[j];
        if ( Tong > target){
            j--;
        }
        else if(Tong == target){
                return {i+1,j+1};}
        else {
            i++;
        }
       }
      return {};
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            // Tránh tràn số khi mảng quá lớn
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid; // Tìm thấy, trả về chỉ mục
            } else if (nums[mid] < target) {
                left = mid + 1; // Tìm ở nửa bên phải
            } else {
                right = mid - 1; // Tìm ở nửa bên trái
            }
        }
        
        return -1; // Không tìm thấ
    }
};

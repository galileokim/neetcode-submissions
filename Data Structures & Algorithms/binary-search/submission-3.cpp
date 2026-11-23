class Solution {
public:
    int search(vector<int>& nums, int target) {
        int beg = 0;
        int end = nums.size();
        int mid = 0;

        while (beg < end) {
            mid = (beg + end) / 2;

            if (target > nums[mid]) {
                beg = mid + 1;
            } else if (target < nums[mid]) {
                end = mid;
            } else {
                return mid;
            }
        }
        return -1;

        // 3, 4
        // always searching the first half
        // if num is in first half do end - 1 because we checked mid
        // 
    }
};

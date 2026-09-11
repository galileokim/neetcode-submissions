class Solution {
    /**
     * @param {number[]} nums
     * @param {number} k
     * @return {number}
     */
    minimumDifference(nums, k) {
        // window size is length of array
        nums.sort()
        if (nums.length < k) {
            return nums[r] - nums[l]
        }

        let l = 0
        let r = k - 1
        let min = nums[r] - nums[l]

        while (r < nums.length) {
            min = Math.min(nums[r] - nums[l], min)
            l += 1
            r += 1
        }

        return min
    }
}

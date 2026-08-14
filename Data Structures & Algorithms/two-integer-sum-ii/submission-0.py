class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        
        #approach from left and right
        # check with numbers from right
        # if its too big move to the right
        # once it becomes too small, move up from the left

        # [1, 2, 3, 6, 7, 8, 9]
        # target: 13

        l = 0
        r = len(numbers) - 1

        while l < len(numbers):
            while (numbers[l] + numbers[r]) > target:
                r -= 1
            while (numbers[l] + numbers[r]) < target:
                l += 1
            
            if (numbers[l] + numbers[r]) == target:
                return [l+1,r+1]
            
        
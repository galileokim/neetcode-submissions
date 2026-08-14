class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        # first, lets have a loop that runs through the nums
        seen = set()
        for num in nums:
            if num in seen:
                return(True)
                break
            else:
                seen.add(num)
        return(False)

        
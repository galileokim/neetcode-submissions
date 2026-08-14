class Solution:
    def maxArea(self, heights: List[int]) -> int:
        l = 0
        r = len(heights) - 1

        maxA = min(heights[l], heights[r]) * (r-l)

        while l < r:
            if heights[l] > heights[r]:
                r -= 1
            else:
                l += 1
    
            maxA = max(maxA, min(heights[l], heights[r]) * (r-l))

        
        return maxA


        
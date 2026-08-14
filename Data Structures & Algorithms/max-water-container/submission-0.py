class Solution:
    def maxArea(self, heights: List[int]) -> int:
        l = 0
        r = len(heights) - 1

        maxA = min(heights[l], heights[r]) * (r-l)

        while l < r:
            if heights[l] > heights[r]:
                r -= 1
            elif heights[l] < heights[r]:
                l += 1
            elif heights[l] == heights[r]:
                if heights[l+1] > heights[r-1]:
                    l += 1
                else:
                    r -= 1
            maxA = max(maxA, min(heights[l], heights[r]) * (r-l))

        
        return maxA


        
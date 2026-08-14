class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        maxL = 0
        l = 0
        seen = {}

        for r, char in enumerate(s):
            if char in seen and seen[char] >= l:
                l = seen[char] + 1
            
            seen[char] = r

            maxL = max(maxL, r - l + 1)
        
        return maxL




        
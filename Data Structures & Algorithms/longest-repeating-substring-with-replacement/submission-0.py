class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        maxL = 0
        l = 0
        seen = {}
        maxCL = 0  

        for r in range(len(s)):
            windowL = r - l + 1

            if s[r] not in seen:
                    seen[s[r]] = 0
            seen[s[r]] += 1
            
            maxCL = max(seen[s[r]], maxCL)
            if windowL - maxCL > k:
                seen[s[l]] -= 1
                l += 1
            else:
                maxL = max(r - l + 1, maxL)
                

        return maxL



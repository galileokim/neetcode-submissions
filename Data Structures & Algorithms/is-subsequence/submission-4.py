class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        pos = 0

        for c in t:
            if c == s[pos] and pos <= len(s) - 1:
                pos += 1
        
        if pos == len(s):
            return True
        
        return False
            

        
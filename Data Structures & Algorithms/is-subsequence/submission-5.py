class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        pos = 0

        for c in t:
            if pos <= len(s) - 1:
                if c == s[pos]:
                    pos += 1
        
        if pos == len(s):
            return True
        
        return False
            

        
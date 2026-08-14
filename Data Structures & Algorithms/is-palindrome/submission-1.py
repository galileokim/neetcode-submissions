class Solution:
    def isPalindrome(self, s: str) -> bool:
        clean = ""

        for c in s:
            if c.isalnum():
                clean += c.lower()
        
        r = len(clean) - 1
        print(clean)
        for i in range(len(clean) // 2):
            if clean[i] != clean[r-i]:
                return False

        return True
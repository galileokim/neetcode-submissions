class Solution:
    def dictMaker(self, s: str) -> dict:
        newDict = {}

        for i in s:
            if i in newDict:
                newDict[i] += 1
            else:
                newDict[i] = 1
        
        return newDict

    def isAnagram(self, s: str, t: str) -> bool:
        dict1 = self.dictMaker(s)
        dict2 = self.dictMaker(t)

        return(dict2 == dict1)
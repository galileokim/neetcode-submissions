class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        l = 0
        r = len(s1) - 1

        if len(s1) > len(s2):
            return False

        count = defaultdict(int)

        for c in s1:
            count[c] += 1

        s2count = defaultdict(int)

        for i in range(len(s1)):
            s2count[s2[i]] += 1

        if s2count == count:
            return True

        for i in range(len(s1), len(s2)):
            s2count[s2[i]] += 1

            s2count[s2[i-len(s1)]] -= 1

            if s2count[s2[i-len(s1)]] == 0:
                del s2count[s2[i-len(s1)]]
            
            if s2count == count:
                return True
        
        return False





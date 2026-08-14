class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        letters = defaultdict(list)

        for s in strs:
            d = [0] * 26

            for i in s:
                d[ord(i) - ord("a")] += 1
                
            letters[tuple(d)].append(s)

        return list(letters.values())     
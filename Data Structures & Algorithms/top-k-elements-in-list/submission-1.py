class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        d = {}

        for num in nums:
            if num in d:
                d[num] += 1
            else:
                d[num] = 1
        
        count = [[] for i in range(len(nums)+1)]
        for n, c in d.items():
            count[c].append(n)
        
        e = []
        for i in range(len(count)-1, -1, -1):
            for n in count[i]:
                e.append(n)
                if len(e) == k:
                    return e
                


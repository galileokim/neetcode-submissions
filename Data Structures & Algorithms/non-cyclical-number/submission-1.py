class Solution:
    def isHappy(self, n: int) -> bool:
        seen = set()

        curr_sum = n

        while curr_sum != 1:
            digits = [int(x) for x in str(curr_sum)]

            new_sum = 0

            for num in digits:
                new_sum += num**2
            
            if new_sum in seen:
                return False
            else:
                seen.add(new_sum)
                curr_sum = new_sum
            
        return True


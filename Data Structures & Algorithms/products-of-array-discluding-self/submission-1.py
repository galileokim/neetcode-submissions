class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        zero_counter = 0
        non_zero_total = 1
        for n in nums:
            if n == 0:
                zero_counter += 1
            else:
                non_zero_total = non_zero_total * n
        
        a = []
        for n in nums:
            if zero_counter >= 2:
                a.append(0)
            elif n == 0 and zero_counter == 1:
                a.append(non_zero_total)
            elif zero_counter == 1:
                a.append(0)
            else:
                a.append(int(non_zero_total/n))
        
        return a
        

        
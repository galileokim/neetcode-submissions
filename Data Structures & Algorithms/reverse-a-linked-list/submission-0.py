# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        #[None -> 0 -> 1 -> 2 -> 3 -> None]
        #[None <- 0 <- 1 <- 2 <- 3 <- None]
        prev = None

        while head != None:
            new_head = head.next
            head.next = prev
            prev = head
            head = new_head
            
        return prev




    
        



        
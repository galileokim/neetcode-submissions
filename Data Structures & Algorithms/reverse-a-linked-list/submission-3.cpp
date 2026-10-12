/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head; // variable to store the head
        ListNode* prev = nullptr; // variable to track the previous
        ListNode* next; // var to track next

        while (curr != nullptr) {
            next = curr->next; // new curr (moving back one)

            curr->next = prev; // curr now points to whatever precedes it

            prev = curr; // moving forward; prev is now curr
            curr = next; // moving forward; curr is now next

            // so essentially, steps are: store next before you reassign curr next
            // to reverse direction
            // reverse direction so curr now points to whatever is before it (prev)
            // move pre and next up one
            // loop ends when curr hits a null ptr
        }

        return prev;
    }
};

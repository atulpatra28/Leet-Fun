# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head

        new_head = self.reverseList(head.next)
        
        # Reverse the current node's next pointer
        head.next.next = head
        head.next = None
        
        # Return the new head of the reversed list
        return new_head
        
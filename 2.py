# ~~~~~~~~CODE SOLUTION 1~~~~~~~~

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        # Dummy node to form the result linked list
        dummy = ListNode(0)
        current = dummy
        carry = 0
        
        # Traverse both lists
        while l1 or l2 or carry:
            # Get the values from l1 and l2, if available
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0
            
            # Calculate the sum of current digits and carry
            total = val1 + val2 + carry
            
            # Update carry for next place
            carry = total // 10
            
            # Create a new node for the current place
            current.next = ListNode(total % 10)
            current = current.next
            
            # Move to the next nodes in l1 and l2
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
        
        # Return the next node of dummy, as dummy is a placeholder
        return dummy.next
    
# ~~~~~~~~CODE SOLUTION 2~~~~~~~~


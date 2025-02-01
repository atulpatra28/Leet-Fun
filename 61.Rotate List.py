# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: Optional[ListNode]
        :type k: int
        :rtype: Optional[ListNode]
        """
        temp=head
        if not head :
            return None
        length=1
        while temp.next is not None:
            temp=temp.next
            length=length+1
        temp.next=head
        temp=head
        k=k%length
        for i in range (length-k-1):
            temp=temp.next
        head=temp.next
        temp.next=None
        return head
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def calc_gcd(self, num1,num2):
        while num2 !=0:
            num1,num2= num2, (num1 % num2)
        return num1

    def insert_node(self,val,prev,cur):
        newnode=ListNode(val)
        newnode.next=cur
        prev.next=newnode
        return newnode

    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev=None
        cur=head
        while cur and cur.next:
            gcd =self.calc_gcd(cur.val, cur.next.val)
            self.insert_node (gcd,cur, cur.next)
            
            cur=cur.next.next
        return head

        
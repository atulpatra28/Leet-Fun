class Solution(object):
    def sos(self,n):
        return sum(int(digit) ** 2 for digit in str(n))
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        visited=set()
        while n!=1 and n not in visited:
            visited.add(n)
            n=self.sos(n)
        return n==1
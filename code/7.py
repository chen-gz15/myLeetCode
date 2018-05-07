#my code,beats 94% 
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x==0:
            return 0
        a=x/abs(x)
        x=abs(x)
        ans=x%10
        while x//10>=1:
            ans*=10
            x//=10
            ans+=x%10
        if ans>=1<<31:
            return 0
        return ans*a
#better code
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        maxInt = 2**31-1
        minInt = -1 * 2**31
        if x < 0:
            y  = -1 * int(str(-x)[::-1])
        else:
            y  = int(str(x)[::-1])
        if y > maxInt or y < minInt:
            return 0
        return y   

#my code
class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        interval=2*(numRows-1)
        if interval==0:
            return s
        ans=""
        pos=0
        for i in range(numRows):
            pos=0
            while pos-i<len(s):
                if i==0:
                    if pos <len(s):
                        ans+=s[pos]
                    pos+=interval
                if (i!=0)&(i!=numRows-1):
                    if pos-i>=0:
                        ans+=s[pos-i]
                    if pos+i<len(s):
                        ans+=s[pos+i]
                    pos+=interval
                if i==numRows-1:
                    if pos+i<len(s):
                        ans+=s[pos+i]
                    pos+=interval
        return ans 
        
#better code
class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        line = ['']*numRows
        row, step = 0 , 1
        
        if numRows == 1 or numRows >= len(s):
            return s
        for ch in s:
            line[row] += ch
            row += step
            if row == 0 or row == numRows-1:
                step *= -1
        
        return ''.join(line)

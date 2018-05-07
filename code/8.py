#my code beats 36%
class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        INT_MAX=(1<<31)-1
        INT_MIN=-(1<<31)
        pos=0
        flag=1
        plus=0;
        ans=0
        if len(str)==0:
            return 0
        while str[pos]==' ':
            pos=pos+1
            if pos==len(str):
                return 0
        if str[pos]=='-' :
            flag=-1
            pos=pos+1
        elif str[pos]=='+':
            pos+=1
        if pos==len(str):
            return 0
        while pos<len(str):
            if str[pos]>='0' and str[pos]<='9':
                ans=ans*10+int(str[pos])
            else:
                return max(INT_MIN,min(ans*flag,INT_MAX))
            pos=pos+1
        return max(INT_MIN,min(ans*flag,INT_MAX))
        
    #better code
    class Solution(object):
    def myAtoi(self, s):
        """
        :type str: str
        :rtype: int
        """
        if len(s) == 0 : return 0
        ls = list(s.strip())
        
        sign = -1 if ls[0] == '-' else 1
        if ls[0] in ['-','+'] : del ls[0]
        ret, i = 0, 0
        while i < len(ls) and ls[i].isdigit() :
            ret = ret*10 + ord(ls[i]) - ord('0')
            i += 1
        return max(-2**31, min(sign * ret,2**31-1))

//better codes
string longestPalindrome(string s) {
    int len = s.size();
    if (len <= 1) return s;
    int lpos = 0, lm = 0; // position of first letter and length
    for ( int i = 0; i < len - 1; i++) {
        if (lm >= (len - i) * 2) return s.substr(lpos,lm);
        int count = 0;
        while (s[i + 1] == s[i] && i++ < len - 1) 
             count++;
        int end = i;
        int first = i - count;
        while (s[--first] == s[++end] && first >= 0 && end < len);
        end--;
        first++;
        if ( lm < end - first + 1){
            lpos = first;
            lm = end - first + 1;
        }
    }
    return s.substr(lpos, lm);
}
//my codes
class Solution {
public:
    string longestPalindrome(string s) {
        int length_odd=0,pos_odd=0,length_even=0,pos_even=0,even=0;
        for(int i=0;i<s.length();i++)
        {
            int k=0;
            while(k<=i&&i+k<s.length())
            {
                if(s[i-k]==s[i+k])
                    k++;
                else
                    break;
            }
            if(length_odd<=k-1)
            {
                length_odd=k-1;pos_odd=i;
            }
            if(i<s.length()-1&&s[i]==s[i+1])
            {
                int j=0;
                even=1;
                while(j<=i&&i+j+1<s.length())
                {
                    if(s[i-j]==s[i+1+j])
                        j++;
                    else
                        break;
                }
                if(length_even<=j-1)
                {
                    length_even=j-1;pos_even=i;
                }
                
            }
        }
        string ans1;
        if(length_odd>length_even||even==0)
                ans1.assign(s,pos_odd-length_odd,2*length_odd+1);            
        else
                ans1.assign(s,pos_even-length_even,2*length_even+2);                
        return ans1;
    }
};

//better codes
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        map<char, int> charMap;
        int start = -1;
        int maxLen = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (charMap.count(s[i]) != 0) {
                start = max(start, charMap[s[i]]);
            }
            charMap[s[i]] = i;
            maxLen = max(maxLen, i-start);
        }
        
        return maxLen;
    }
};
//my codes
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start=0,end=0,length=1;
        if(s.size()==0)
            return 0;
        while(end<s.size()-1)
        {
            end++;
            for(int i=start;i<end;i++)
            {
                if(s[end]==s[i])
                {
                    if(length<end-start)
                        length=end-start;
                    start=i+1;
                }
            }
            if(end==s.size()-1)
                if(length<end-start+1)
                    length=end-start+1;
        }
        return length;
        
    }
};

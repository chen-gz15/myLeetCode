#my code,best code!
class Solution(object):
    def uniqueMorseRepresentations(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        excel=[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        unistr=set()
        for word in words:
            tempstr=''
            for w in word:
                tempstr+=excel[ord(w)-ord('a')]
            unistr.add(tempstr)
        return len(unistr)

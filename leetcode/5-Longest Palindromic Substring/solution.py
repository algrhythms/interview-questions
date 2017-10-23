class Solution(object):
    # ExpandAroundCenter Solution
    def expand_around_center(self, s, l, r):
        slen = len(s)
        while l >= 0 and r < slen and s[l] == s[r]:
            l -= 1
            r += 1
        return r - l - 1

    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        slen = len(s)
        start = 0
        end = 0
        for i in xrange(slen - 1):
            len1 = self.expand_around_center(s, i, i)
            len2 = self.expand_around_center(s, i, i + 1) if s[i] == s[i + 1] else 0
            leng = max(len1, len2)
            if leng > end - start:
                start = i - (leng / 2) + 1 if leng % 2 == 0 else i - (leng / 2)
                end = i + (leng / 2)
        return s[start:end + 1]


# Test
s = Solution()
print s.longestPalindrome("babad")

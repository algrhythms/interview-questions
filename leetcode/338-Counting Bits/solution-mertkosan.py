class Solution(object):
    def countBits(self, num):
        res = [0]
        for i in range(1, num + 1):
            res.append(res[i & (i - 1)] + 1)
        return res

# s = Solution()
# m = s.countBits(10)

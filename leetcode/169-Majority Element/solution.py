class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count = 0
        result = None
        for num in nums:
            if count == 0:
                result, count = num, 1
            elif num == result:
                count += 1
            else:
                count -= 1
        return result
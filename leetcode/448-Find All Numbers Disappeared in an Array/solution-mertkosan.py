class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        for num in nums:
            numabs = abs(num)
            if nums[numabs-1] > 0:
                nums[numabs-1] *= -1
        
        result = []
        for i, num in enumerate(nums):
            if num > 0:
                result.append(i+1)
        return result

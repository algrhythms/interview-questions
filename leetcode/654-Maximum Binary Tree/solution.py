# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def constructMaximumBinaryTree(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        if len(nums) == 0:
        	return None

        max_elm = max(nums)
        index_elm = nums.index(max_elm)
        treeNode = TreeNode(max_elm)
        treeNode.left = self.constructMaximumBinaryTree(nums[:index_elm])
        treeNode.right = self.constructMaximumBinaryTree(nums[index_elm+1:])
        return treeNode

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
	    self.val = x
        self.left = None
        self.right = None

class Solution(object):      
    def mergeTrees(self, t1, t2):
        
        if t1 is None:
            return t2
        
        if t2 is None:
            return t1
        
        if t1 is not None and t2 is not None:
            newt = TreeNode(t1.val+t2.val)
            newt.left = self.mergeTrees(t1.left, t2.left)
            newt.right = self.mergeTrees(t1.right, t2.right)
        
        return newt
		
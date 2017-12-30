from collections import deque

# Definition for a binary tree node.
class TreeNode(object):
     def __init__(self, x):
         self.val = x
         self.left = None
         self.right = None

class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        queue = deque([(root, 1)])
        
        elm = (None, 0)
        while len(queue) > 0 and root != None:
            elm = queue.popleft()
            node, depth = elm[0], elm[1]
            
            if node.left != None:
                queue.append((node.left, depth+1))
                
            if node.right != None:
                queue.append((node.right, depth+1))
        
        return elm[1]
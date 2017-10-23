# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None or head.next is None:
            return head

        next = head
        ite = 0
        head_asil = None
        while next and next.next:
            ite += 1
            head, pre, next = next, head.next, head.next.next
            pre.next = head
            head.next = next.next if next and next.next else next
            if ite == 1:
                head_asil = pre
        return head_asil

# Test

# s = Solution()
# head = ListNode(1)
# head.next = ListNode(2)
# head.next.next = ListNode(3)
# head.next.next.next = ListNode(4)
# result = s.swapPairs(head)
# print result

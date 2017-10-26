class ListNode(object):
    def __init__(self, key, value, next=None, prev=None):
        self.key = key
        self.value = value
        self.next = next
        self.prev = prev

class LinkedList(object):
    def __init__(self, capacity):
        self.size = 0
        self.capacity = capacity

        self.cacheDict = dict()
        self.head = None
        self.tail = None

    def hasKey(self, key):
        return self.cacheDict.get(key) is not None

    def hasSpace(self):
        return self.size < self.capacity

    def headKey(self):
        return self.head.key

    def changeValue(self, key, value):
        node = self.cacheDict[key]
        node.value = value

    def append(self, key, value):
        self.size += 1
        if self.tail is None:
            self.tail = ListNode(key, value)
            self.head = self.tail
            self.cacheDict[key] = self.tail
        else:
            self.tail.prev = ListNode(key, value, self.tail)
            self.cacheDict[key] = self.tail.prev
            self.tail = self.tail.prev

    def remove(self, key):
        self.size -= 1
        node = self.cacheDict.get(key)
        value = node.value
        if node.prev is not None and node.next is not None:
            node.prev.next = node.next
            node.next.prev = node.prev
        elif node.prev is not None: # node.next is None
            node.prev.next = None
            self.head = node.prev
        elif node.next is not None: # node.prev is None
            node.next.prev = None
            self.tail = node.next
        else:
            self.head = None
            self.tail = None
        node.next, node.prev = None, None
        del node
        del self.cacheDict[key]
        return value


class LRUCache(object):

    def __init__(self, capacity):
        self.cacheList = LinkedList(capacity)
        

    def get(self, key):
        if self.cacheList.hasKey(key):
            value = self.cacheList.remove(key)
            self.cacheList.append(key, value)
            return value
        else:
            return -1

    def put(self, key, value):
        if self.cacheList.hasKey(key):
            self.cacheList.remove(key)
            self.cacheList.append(key, value)
        else:
            if not self.cacheList.hasSpace():
                headKey = self.cacheList.headKey()
                self.cacheList.remove(headKey)
            self.cacheList.append(key, value)

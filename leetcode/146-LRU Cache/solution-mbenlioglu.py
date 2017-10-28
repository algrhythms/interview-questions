"""
    Created by mbenlioglu on 10/28/2017
"""


class LRUCache(object):
    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.__capacity = capacity
        self.__size = 0
        self.__index_dict = {}
        self.__reverse_dict = {}
        self.__cache = [0 for _ in range(capacity)]
        self.__usage_list = [[0, 0] for _ in range(capacity + 2)]  # Imitates doubly linked list. Index -1 is head, -2 is tail

        self.__usage_list[-1][0] = None  # head->prev = NULL
        self.__usage_list[-1][1] = -2  # head->next = tail
        self.__usage_list[-2][0] = -1  # tail->prev = head
        self.__usage_list[-2][1] = None  # tail->next = NULL

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key in self.__index_dict:
            index = self.__index_dict[key]

            # update usage_list
            prev, next_ = self.__usage_list[index]
            self.__usage_list[prev][1] = next_  # node->prev->next = node->next
            self.__usage_list[next_][0] = prev  # node->next->prev = node->prev

            self.__usage_list[index][0] = -1  # node->prev = head
            self.__usage_list[index][1] = self.__usage_list[-1][1]  # node->next = head->next
            self.__usage_list[self.__usage_list[-1][1]][0] = index  # head->next->prev = node
            self.__usage_list[-1][1] = index  # head->next = node

            return self.__cache[index]
        else:
            return -1

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        if key in self.__index_dict:
            # update value
            index = self.__index_dict[key]
            self.__cache[index] = value

            # update usage_list
            prev, next_ = self.__usage_list[index]
            self.__usage_list[prev][1] = next_  # node->prev->next = node->next
            self.__usage_list[next_][0] = prev  # node->next->prev = node->prev

            self.__usage_list[index][0] = -1  # node->prev = head
            self.__usage_list[index][1] = self.__usage_list[-1][1]  # node->next = head->next
            self.__usage_list[self.__usage_list[-1][1]][0] = index  # head->next->prev = node
            self.__usage_list[-1][1] = index  # head->next = node
        elif self.__size < self.__capacity:
            index = self.__size
            # insert item
            self.__index_dict[key] = index
            self.__reverse_dict[index] = key
            self.__cache[index] = value

            # update usage_list
            self.__usage_list[index][0] = -1  # node->prev = head
            self.__usage_list[index][1] = self.__usage_list[-1][1]  # node->next = head->next
            self.__usage_list[self.__usage_list[-1][1]][0] = index  # head->next->prev = node
            self.__usage_list[-1][1] = index  # head->next = node

            self.__size = self.__size + 1
        else:
            # dump least recent used
            lru = self.__usage_list[-2][0]  # lru = tail->prev
            index = self.__reverse_dict.pop(lru)
            del self.__index_dict[index]

            # update usage_list
            self.__usage_list[-2][0] = self.__usage_list[lru][0]  # tail->prev = lru->prev
            self.__usage_list[self.__usage_list[lru][0]][1] = -2  # lru->prev->next = tail

            self.__usage_list[lru][0] = -1  # node->prev = head
            self.__usage_list[lru][1] = self.__usage_list[-1][1]  # node->next = head->next
            self.__usage_list[self.__usage_list[-1][1]][0] = lru  # head->next->prev = node
            self.__usage_list[-1][1] = lru  # head->next = node

            # add new item
            self.__index_dict[key] = lru
            self.__reverse_dict[lru] = key
            self.__cache[lru] = value


# if __name__ == '__main__':
#     obj = LRUCache(2)
#     obj.put(2, 1)
#     obj.put(2, 2)
#     print obj.get(2)
#     obj.put(1, 1)
#     obj.put(4, 1)
#     print obj.get(2)

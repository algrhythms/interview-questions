"""
author: mertkosan
createdAt: 11/19/2017
"""
from time import time


class Solution(object):
    def __init__(self):
        self.keep = {
            '1': {'A'}, '2': {'B'}, '3': {'C'}, '4': {'D'}, '5': {'E'}, '6': {'F'}, '7': {'G'},
            '8': {'H'}, '9': {'I'}, '10': {'J'}, '11': {'AA', 'K'}, '12': {'AB', 'L'}, '13': {'AC', 'M'},
            '14': {'AD', 'N'}, '15': {'AE', 'O'}, '16': {'AF', 'P'}, '17': {'AG', 'Q'}, '18': {'AH', 'S'},
            '19': {'AS', 'S'}, '20': {'T'}, '21': {'BA', 'U'}, '22': {'BB', 'V'}, '23': {'BC', 'W'},
            '24': {'AD', 'X'}, '25': {'AE', 'Y'}, '26': {'AF', 'Z'}
        }

    # returns set, possible values of keys, length 2
    def find_value(self, key):
        if key[0] == '0' or key[1] == '0':
            return {}
        left = self.keep[key[0]]
        right = self.keep[key[1]]
        return left | right

    def decode_number(self, number):
        return self.decode_number_helper(number, None)

    def decode_number_helper(self, left, right):
        if right is None:
            setl = self.keep.get(left)
            if setl is not None:
                return setl
            elif len(left) <= 2:
                temp_set = self.find_value(left)
                self.keep[left] = temp_set
                return temp_set
            else:  # union
                union = set()
                for i in xrange(1, len(left)):
                    left_key, right_key = left[:i], left[i:]
                    temp_set = self.decode_number_helper(left_key, right_key)
                    self.keep[(left_key, right_key)] = temp_set
                    union = union | temp_set
                self.keep[left] = union
                return union
        else:
            setlr = self.keep.get((left, right))
            if setlr is not None:
                return setlr
            else:
                setlcross = self.decode_number_helper(left, None)
                setrcross = self.decode_number_helper(right, None)
                return {x + y for x in setlcross for y in setrcross}


start = time()
s = Solution()
result = s.decode_number("11111111111111111111")
print result
end = time()
print end - start

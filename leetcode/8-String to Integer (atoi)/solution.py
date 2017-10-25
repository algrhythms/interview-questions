class Solution(object):
                
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        # strip
        str = str.strip()
        
        # if empty return 0
        if len(str) == 0:
            return 0
        
        # ascii
        diff = 48
        
        # overflows
        INT_MAX = 2147483647
        INT_MIN = -2147483648
        
        # determine sign
        sign = 1
        if str[0] == '-':
            str = str[1:]
            sign = -1
        elif str[0] == '+':
            str = str[1:]
        
        # normalize str
        for i, ch in enumerate(str):
            value = ord(ch) - diff
            if value < 0 or value > 9:
                str = str[:i]
                
        leng = len(str)
        result = 0
        for i, ch in enumerate(str):
            value = ord(ch) - diff
            result += value * pow(10, leng-i-1)
            if value < 0:
                return 0
        
        result = result * sign
        
        if result > INT_MAX:
            return INT_MAX
        elif result < INT_MIN:
            return INT_MIN
        else:
            return result
            
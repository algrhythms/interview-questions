class Solution(object):
    digits_dict = {
        "1": "",
        "2": "abc",
        "3": "def",
        "4": "ghi",
        "5": "jkl",
        "6": "mno",
        "7": "pqrs",
        "8": "tuv",
        "9": "wxyz"
    }

    def createCombinations(self, letter_list):
        number_of_combination = 1
        for letter in letter_list:
            number_of_combination *= len(letter)
        result_list = []
        if number_of_combination != 1:
            for i in range(0, number_of_combination):
                element = ''
                quotient = i
                for letter in reversed(letter_list):
                    remainder = quotient % len(letter)
                    quotient = quotient / len(letter)
                    element = letter[remainder] + element
                result_list.append(element)
        return result_list

    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        letter_list = []
        for ch in digits:
            letter_list.append(self.digits_dict[ch])
        return self.createCombinations(letter_list)


# Test
s = Solution()
sample = s.letterCombinations("23")
print sample

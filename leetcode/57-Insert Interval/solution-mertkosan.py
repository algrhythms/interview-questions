"""
author: mertkosan
createdAt: 11/24/2017
"""


# Definition for an interval.
class Interval(object):
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e


class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        if len(intervals) == 0:
            return [newInterval]

        keepLeft = None
        isFinished = False
        newIntervals = []
        new_start, new_end = newInterval.start, newInterval.end
        for interval in intervals:
            if isFinished:
                newIntervals.append(interval)
            else:
                start, end = interval.start, interval.end
                if new_start <= end and new_end <= end:
                    isFinished = True
                    if new_end < start:  # Case 1
                        newIntervals.append(Interval(keepLeft if keepLeft is not None else new_start, new_end))
                        newIntervals.append(Interval(start, end))
                    elif new_start < start and new_end <= end:  # Case 2
                        newIntervals.append(Interval(keepLeft if keepLeft is not None else new_start, end))
                    elif end >= new_end >= new_start >= start:  # Case 3
                        newIntervals.append(Interval(keepLeft if keepLeft is not None else start, end))
                else:  # new_start > start or new_end > end
                    if new_end > end >= new_start >= start:  # Case 4
                        keepLeft = keepLeft if keepLeft is not None else start
                    elif new_start > end:  # Case 5
                        newIntervals.append(Interval(start, end))
                    elif new_start <= start and new_end > end:  # Case 6
                        keepLeft = keepLeft if keepLeft is not None else new_start

        # intervals are finished, but there should be operation left
        if not isFinished:
            newIntervals.append([keepLeft if keepLeft is not None else new_start, new_end])

        return newIntervals


# s = Solution()
# sample = [Interval(1, 3), Interval(6, 9)]
# sample2 = [Interval(1, 2), Interval(3, 5), Interval(6, 7), Interval(8, 10), Interval(12, 16)]
# sample3 = [Interval(1, 5)]
# sample4 = [Interval(0, 7), Interval(8, 8), Interval(9, 11)]
# i = Interval(4, 13)
# result = s.insert(sample4, i)
# print result

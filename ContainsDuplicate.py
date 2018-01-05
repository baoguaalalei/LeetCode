# -*- coding: utf-8 -*-
"""
Created on Fri Jan  5 17:02:31 2018

@author: xuwh
"""
class Solution:
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        dic = {}
        for i,v in enumerate(nums):
            if v in dic and i - dic[v] <= k:  #检查字典中是否含有键值为v的项
                return True
            dic[v] = i
        return False

res = Solution()
data = [1,2,4,5,6,8,9,13,4,2]
print(res.containsNearbyDuplicate(data,10)) 
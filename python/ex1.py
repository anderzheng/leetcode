class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        _dict = {}
        i = 0
        for tmp in nums:
            if _dict.get(target-tmp) is not None:
                return [_dict[target-tmp], i]
            _dict[tmp] = i
            i += 1

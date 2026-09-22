class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left, right = 0, len(numbers) - 1
        while left < right:
            cal = numbers[left] + numbers[right]
            if cal == target:
                return [left +1 , right +1]
            elif cal < target:
                left += 1
            elif cal > target:
                right -= 1     
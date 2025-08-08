import math

class Solution:
    def find132pattern(self, nums):
        stack = []
        s3 = -math.inf
        for i in range(len(nums) - 1, -1, -1):
            num = nums[i]
            if num < s3:
                return True
            while stack and num > stack[-1]:
                s3 = stack.pop()
            stack.append(num)       
        return False

if __name__ == "__main__":
    try:
        nums_list = list(map(int, input().split()))
        sol = Solution()
        result = sol.find132pattern(nums_list)
        print(str(result).lower())
    except (IOError, ValueError):
        print("false")
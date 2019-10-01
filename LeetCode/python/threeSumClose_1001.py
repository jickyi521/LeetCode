
def threeSumClose(nums, target):
    nums.sort()
    ans = 0
    diff = float("inf")
    for i in range(len(nums)):
        start, end = i+1, len(nums)-1
        while start<end:
            sum = nums[i] + nums[start] + nums[end]
            if sum > target:
                if abs(target - sum) < diff:
                    diff = abs(target - sum)
                    ans = sum
                end -= 1
            else:
                 if abs(target - sum) < diff:
                    diff = abs(target - sum)
                    ans = sum
                 start += 1
    return ans


print(threeSumClose([-1, 2, 1, -4], 1))
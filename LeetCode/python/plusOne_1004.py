def plusOne(nums):
    carry = 1
    for i in reversed(range(len(nums))):
        num = (nums[i] + carry) % 10
        carry = 1 if num < nums[i] else 0
        nums[i] = num
    if carry == 1:
        return [1] + nums
    return nums

print(plusOne([4,3,2,9]))
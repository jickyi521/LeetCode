
def maxSubArray(nums):
    if len(nums) == 0:
        return 0
    preSum = maxSum = nums[0]
    for i in range(1,len(nums)):
        preSum = max(preSum + nums[i], nums[i])
        maxSum = max(maxSum, preSum)
    return preSum

print(maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))
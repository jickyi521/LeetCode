
def searchInsert(nums, target):
    for i in range(len(nums)):
        temp = nums[i]
        if temp >= target:
            return i
    return len(nums)

print(searchInsert([1,3,5,6],2))
def removeDuplicates(nums):
    if len(nums) <= 1:
        return len(nums)

    nums.sort()
    slow = 0
    for i in range(1, len(nums)):
        if nums[slow] != nums[i]:
            slow += 1
            nums[slow] = nums[i]
    return slow +1


print(removeDuplicates([1,1,1,2,3,4,2])) 
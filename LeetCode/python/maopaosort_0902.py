
def maopaosort(nums):
    n = len(nums)
    for i in range(n):
        max = nums[i]
        for j in range(i+1, n):
            item = nums[j]
            if max < item:
                nums[i] = item
                nums[j] = max
                max = item
    return nums

print(maopaosort([12, 2, 1, 7, 11, 15]))
    
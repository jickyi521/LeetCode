
def removeNodeElement(nums, value):
    sum = 0
    for i in range(len(nums)):
        if nums[i] != value:
            sum += 1
    return sum

print(removeNodeElement([3,2,2,3], 3))

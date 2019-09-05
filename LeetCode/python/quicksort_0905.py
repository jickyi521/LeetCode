import random

def quick_sort(nums):
    if len(nums) <=1:
        return nums
    left, right, mid = [],[],[]
    pivot = random.choice(nums)
    for num in nums:
        if num == pivot:
            mid.append(num)
        elif num < pivot:
            left.append(num)
        else:
            right.append(num)
    return quick_sort(left) + mid + quick_sort(right)

numbers = [9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 0]
print(quick_sort(numbers))
assert quick_sort(numbers) == [0, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9]
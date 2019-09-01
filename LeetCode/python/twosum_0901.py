
# class Solution

def twosum(nums, target):
    n = len(nums)
    for i in range(n):
        item = nums[i]
        remainItem = target - item
        # print('remainItem', remainItem)
        for j in range(i+1, n):
            # print('j', j, nums[j])
            if remainItem == nums[j]:
                # print(i, j)
                return [i, j]

# print(twosum([-1,-2,-3,-4,-5], -8))
print(twosum([2, 7, 11, 15], 9))

# i = 5

# def f(i):
#     print(i)

# i = 6
# f(6)

# a, b = 0, 1
# while a < 10:
#   print(a)
#   a, b = b , a+b
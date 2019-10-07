
#爬楼梯，用递归的方式， f(n) = f(n-1) + f(n-2)
def climbStairs(n):
    if n<=1:
        return 1
    pre, ppre = 1,1
    for i in range(2, n+1):
        tmp = pre
        pre = ppre+pre
        ppre = tmp
    return pre

def climbStairs2(n):
    if n <= 2:
        return n
    else:
        return climbStairs2(n-1)+climbStairs2(n-2)

print(climbStairs(5))
print(climbStairs2(5))
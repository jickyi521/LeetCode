
def myPow(x, n):
    if n<0:
        n=-n
        x = 1/x
    ans = 1
    while n:
        if n & 1:
         ans *= x
        x *= x
        n>>=1
    return ans

print(myPow(2,-2))
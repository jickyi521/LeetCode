def mySqrt(x):
    left, right=0,x/2+1
    while left < right:
        mid = (left+right+1)/2
        square=mid*mid
        if square>x:
            right = mid-1
        else:
            left = mid
    return left



print(mySqrt(3))
print(mySqrt(9))
print(mySqrt(16))
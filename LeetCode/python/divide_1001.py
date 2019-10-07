
def divide(dividend, divisor):
    if divisor == 0:
        return 0x7fffffff
    sign = 1
    if dividend * divisor < 0:
        sign = -1
    ans = 0
    cnt = 1
    dividend = abs(dividend)
    divisor = abs(divisor)
    subSum = divisor
    while dividend >= divisor:
        while (subSum << 1) <= dividend:
            cnt <<=1
            subSum <<=1
        ans+=cnt
        cnt=1
        dividend-=subSum
        subSum=divisor
    return max(min(sign*ans, 0x7fffffff), -2147483648)


print(divide(10,3))
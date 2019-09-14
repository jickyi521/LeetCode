def reverse(num):
    numStr = str(num)
    n = len(numStr)
    strxx = ''
    if num >= 0:
        strxx = numStr[::-1]
        # print(strxx)
        return int(strxx) if int(strxx) <= 2147483647 else 0
    else:
        strxx = numStr[1:n]
        strxx = strxx[::-1]
        # print(-int(strxx))
        return -int(strxx) if -int(strxx) >= -2147483648 else 0   

print(reverse(-1234))
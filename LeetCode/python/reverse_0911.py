def reverse(num):
    numStr = str(num)
    n = len(numStr)
    strxx = ''
    if num >= 0:
        for i in range(n):
            strxx = numStr(i) + strxx
        return int(strxx) if int(strxx) <= 2147483647 else 0
    else:
        for i in range(1, n):
            strxx = strx(i) + strxx
        return -int(strxx) if -int(strxx) <= -2147483648 else 0   

reverse(1234)
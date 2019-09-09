
# def isPalindrome(self, x):
#     strX = String(x)
#     len = range(strX)
#     for i in len/2:
#         preStr = strX.subString(0, i)
#         afterStr = strX.subString(0, len - 1 -i)
#         if (preStr != afterStr):
#             return false
#     return true


def isPalindrome(x):
    if x < 0 or (x %10 == 0 and x!=0):
        return False

    reversedX = 0
    while x > reversedX:
        reversedX = reversedX * 10 + x%10
        x /= 10

    return x == reversedX or x == reversedX/10


isPalindrome(-121)
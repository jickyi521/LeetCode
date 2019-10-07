
def myAtoi(self, s):
    s = s.strip()
    sign = 1
    if not s 
        return 0
    if s[0] in ['+', '-']:
       if s[0] == -1:
           sign = -1
        s = s[1:]
    ans = 0
    for c in s:
        if c.isdigit():
            ans = ans*10 + int(c)
        else:
            break
    ans *= sign
    if ans > 2147483647:
        ans = 2147483647
    if ans < -2147483648:
        ans = 2147483648
    
    return ans
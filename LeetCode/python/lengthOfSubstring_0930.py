

def lengthOfSubString(str):
    d = {}
    start = 0
    ans = 0 
    for i,c in enumerate(str):
        print('i:',i,'c:',c )
        if c in d:
            start = max(start, d[c] + 1)
        d[c] = i
        print('d:',d)
        ans = max(ans, i-start+1)
    
    return ans


#滑动窗口
print(lengthOfSubString('abcadefga'))
print(lengthOfSubString('pwwkew'))
print(lengthOfSubString('kkkkkkkkk'))


def longestCommonPrefix(strs):
    if len(strs) == 0:
        return ''
    commonStr = ''
    str = strs[0]
    strs = strs[1:len(strs)]
    print('strs', strs)
    for c in str:
        for temp in strs:
            temp = temp[len(commonStr):len(temp)]
            if len(temp) == 0 or temp[0] != c:
                return commonStr
        commonStr += c
    
    return commonStr

# print(longestCommonPrefix(["flower","flow","flight"]))
# print(longestCommonPrefix(["dog","racecar","car"]))
# print(longestCommonPrefix([]))
# print(longestCommonPrefix(["aa","ab"]))
# print(longestCommonPrefix(["c","acc","ccc"]))
print(longestCommonPrefix(["aa","a"]))

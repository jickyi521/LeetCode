
def indexOfString(haystack, needle):
    if len(haystack) == len(needle):
        if haystack == needle:
            return 0
        else: 
            return -1
    
    for i in range(len(haystack)):
        k = i
        j=0
        while j<len(needle) and k<len(haystack) and haystack[k] == needle[j]:
            j+=1
            k+=1
            if j == len(needle):
                return i

    return -1 if needle else 0


print(indexOfString("hello", "ll"))
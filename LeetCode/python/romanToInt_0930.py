
def romainToInt(s):
    d = {"I":1, "V":5, "X":10, "L":50, "C":100, "D":500, "M":1000}
    ans = 0
    print(s)
    for i in range(0, len(s)-1):
        c = s[i]
        print('i',i ,'c',c)
        cafter = s[i+1]
        if d[c]<d[cafter]:
            ans -= d[c]
        else:
            ans += d[c]
    ans += d[s[-1]]

    return ans

print(romainToInt("MCMXCIV"))
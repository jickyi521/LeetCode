
def lengthOfLastWord(strs):
    strsArray = strs.split(" ")
    if len(strsArray) > 0:
        return strsArray[len(strsArray) - 1]
    else: return 0

print(lengthOfLastWord("Hello World"))
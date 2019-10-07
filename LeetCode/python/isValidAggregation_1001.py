
def isValidAggregation(strs):
    stack = []
    d = ["()", "[]", "{}"]
    for i in range(len(strs)):
        # print("i", i)
        stack.append(strs[i])
        if len(stack)>=2 and stack[-2]+stack[-1] in d:
            stack.pop()
            stack.pop()
    return len(stack) == 0

print(isValidAggregation("(((())))"))

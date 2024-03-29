
def multiply(num1, num2):
    ans = [0]*(len(num1) + len(num2))
    for i, n1 in enumerate(reversed(num1)):
        for j, n2 in enumerate(reversed(num2)):
            ans[i+j] += int(n1) + int(n2)
            ans[i+j+1] += ans[i+j]/10
            ans[i+j]%=10
    
    while len(ans)>1 and ans[-1]==0:
        ans.pop()
    
    return "".join(map(str, ans[::-1]))

print(multiply("123","456"))

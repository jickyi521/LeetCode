
def permute(nums):
    res = []
    visisted = set([])
    def dfs(nums, path, visisted, res):
        if len(nums) == len(path):
            print("success ", path)
            res.append(path+[])
            return 
        for i in range(len(nums)):
            if i not in visisted:
                visisted.add(i)
                path.append(nums[i])
                dfs(nums, path, visisted, res)
                path.pop()
                visisted.discard(i)
    
    dfs(nums, [], visisted, res)
    return res


# print(permute([1,2,3]))
print(permute([1,1,2]))
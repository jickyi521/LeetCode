
def permute2(nums):
    res = []
    visisted = set([])
    nums.sort()
    def dfs(nums, path, visisted, res):
        if len(nums) == len(path):
            print("success ", path)
            res.append(path+[])
            return 
        for i in range(len(nums)):
            if i in visisted:
                continue
            if i>0 and nums[i] == nums[i-1] and i-1 not in visisted:
                continue
            visisted.add(i)
            path.append(nums[i])
            dfs(nums, path, visisted, res)
            path.pop()
            visisted.discard(i)
    
    dfs(nums, [], visisted, res)
    return res


# print(permute([1,2,3])) TODO
print(permute2([1,1,2])) 
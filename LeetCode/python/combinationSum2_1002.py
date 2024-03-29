
def combinationSum2(candidates, target):
    def dfs(candidates, start, target, path, res):
        if target == 0:
            print('success', path)
            return res.append(path+[])
        for i in range(start, len(candidates)):
            print('i:', i, 'path:', path, 'target:', target)
            if target - candidates[i] >= 0:
                path.append(candidates[i])
                dfs(candidates, i+1, target - candidates[i], path, res)
                path.pop()
    
    res = []
    dfs(candidates, 0, target, [], res)

    return res

#TODO
print(combinationSum2([10,1,2,7,6,1,5], 8))


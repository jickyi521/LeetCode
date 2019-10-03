def getPemutation(n, k):
    def dfs(num, start, path, visited, sumDic, res):

        if len(path) == num:
            res.append(path+[])
            sumDic['sum'] += 1
            print('sum:', sumDic, 'success', path, 'k',k)
            if sumDic['sum'] == k: 
                print('bingo sum:', sumDic, 'success', path)
                # return path

        for i in range(1, num+1):
            if i in visited:
                continue
            else:
                path.append(i)
                visited.add(i)
                dfs(num, i+1, path, visited, sumDic, res)
                path.pop()
                visited.discard(i)

    res = []
    visisted = set([])
    sumDic = {}
    sumDic['sum'] = 0
    dfs(n, 1, [], visisted, sumDic,res)
    return res[k-1]

print(getPemutation(3, 3))


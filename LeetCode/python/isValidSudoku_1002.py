
def isValidSudoku(board):
    cacheCol = []
    cacheRow = []
    cacheBox = []

    for i in range(0, 9):
        for j in range(0,9):
            ib = (i/3)*3 + j/3
            if board[i][j] ==".":
                continue
            num = board[i][j] - 1
            if cacheRow[i][num] != 0 or cacheCol[j][num] != 0 or cacheBox[ib][num] != 0:
                return False
            cacheRow[i][num] = 1
            cacheCol[j][num] = 1
            cacheBox[ib][num] = 1
    return True

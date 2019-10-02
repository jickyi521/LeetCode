
def rotate(matrix):
    h = len(matrix)
    w = len(matrix[0])
    for i in range(h):
        for j in range(w/2):
            matrix[i][j], matrix[i][w-j-1] = matrix[i][w-j-1], matrix[i][j]

    for i in range(h):
        for j in range(w-i-1):
            matrix[i][j], matrix[w-1-j][h-1-i] = matrix[w-1-j][h-1-i], matrix[i][j]

    return matrix         

print(rotate([
    [1,2,3],
    [4,5,6],
    [7,8,9]
]))
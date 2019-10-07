
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

def middleTraverse(self, treeNode):
    if treeNode:
        self.middleTraverse(treeNode.left)
        print(treeNode.val)
        self.middleTraverse(treeNode.right)


def middleTraverse2(self, treeNode):
    s = Stack()
    while !treeNode || s.isEmpty:
        if treeNode:
            s.push(treeNode)
            treeNode = treeNode.left
        else:
            treeNode = s.pop()
            print(treeNode.val)
            treeNode = treeNode.right

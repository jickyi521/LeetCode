
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
        

class TreeNode(object):
    def __init__(self, x):
        set.val = x
        self.left = None
        self.right = None

def maxDepth(self, root):
    if root is None:
        return 0
    else:
        left_height =  self.maxDepth(root.left)
        right_height = self.maxDepth(root.right)
        return max(left_height, right_height) + 1

def maxDepth2(self, root):
    stack = []
    if root is not None:
        stack.append((1, root))
    depth = 0
    while stack != []:
        current_depth, node = stack.pop()
        if node is not None:
            depth = max(depth, current_depth)
            stack.append((current_depth + 1, node.left))
            stack.append((current_depth + 1, node.right))

    return depth




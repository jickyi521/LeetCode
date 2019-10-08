
def hasCycle(headNode):
    s = set()
    while headNode:
        if headNode in s:
            return True
        else:
            s.add(headNode)
            headNode = headNode.next
    return False
